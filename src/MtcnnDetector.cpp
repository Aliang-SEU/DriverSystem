#include "MtcnnDetector.h"

MtcnnDetector::MtcnnDetector(const string& proto_model_dir) {

    Caffe::set_mode(Caffe::GPU);
    PNet_.reset(new Net<float>((proto_model_dir + "/mtcnnCaffe/det1.prototxt"), TEST));
    PNet_->CopyTrainedLayersFrom(proto_model_dir + "/mtcnnCaffe/det1.caffemodel");
    RNet_.reset(new Net<float>((proto_model_dir + "/mtcnnCaffe/det2.prototxt"), TEST));
    RNet_->CopyTrainedLayersFrom(proto_model_dir + "/mtcnnCaffe/det2.caffemodel");
    ONet_.reset(new Net<float>((proto_model_dir + "/mtcnnCaffe/det3.prototxt"), TEST));
    ONet_->CopyTrainedLayersFrom(proto_model_dir + "/mtcnnCaffe/det3.caffemodel");
//    ONet_.reset(new Net<float>((proto_model_dir + "/mtcnnCaffe/det3-half.prototxt"), TEST));
//    ONet_->CopyTrainedLayersFrom(proto_model_dir + "/mtcnnCaffe/det3-half.caffemodel");

    Blob<float>* input_layer;
    input_layer = PNet_->input_blobs()[0];
    int num_channels_ = input_layer->channels();
    CHECK(num_channels_ == 3) << "Input layer should have 3 channels.";
}

float MtcnnDetector::IoU(float xmin, float ymin, float xmax, float ymax,
    float xmin_, float ymin_, float xmax_, float ymax_, bool is_iom) {

    float iw = std::min(xmax, xmax_) - std::max(xmin, xmin_) + 1;
    float ih = std::min(ymax, ymax_) - std::max(ymin, ymin_) + 1;
    if (iw <= 0 || ih <= 0)
        return 0;
    float s = iw*ih;
    if (is_iom) {
        float ov = s / std::min((xmax - xmin + 1)*(ymax - ymin + 1), (xmax_ - xmin_ + 1)*(ymax_ - ymin_ + 1));
        return ov;
    }
    else {
        float ov = s / ((xmax - xmin + 1)*(ymax - ymin + 1) + (xmax_ - xmin_ + 1)*(ymax_ - ymin_ + 1) - s);
        return ov;
    }
}
std::vector<FaceInfo> MtcnnDetector::NMS(std::vector<FaceInfo>& bboxes,
                           float thresh, char methodType) {
    std::vector<FaceInfo> bboxes_nms;
    if (bboxes.size() == 0) {
        //没检测到人脸直接退出
        return bboxes_nms;
    }
    //按置信度排序人脸框
    std::sort(bboxes.begin(), bboxes.end(), CompareBBox);

    int32_t select_idx = 0;
    int32_t num_bbox = static_cast<int32_t>(bboxes.size());
    std::vector<int32_t> mask_merged(num_bbox, 0);
    bool all_merged = false;

    while (!all_merged) {
        while (select_idx < num_bbox && mask_merged[select_idx] == 1)
            select_idx++;
        if (select_idx == num_bbox) {
            all_merged = true;
            continue;
        }

        bboxes_nms.push_back(bboxes[select_idx]);
        mask_merged[select_idx] = 1;

        FaceBox select_bbox = bboxes[select_idx].bbox;
        float area1 = static_cast<float>((select_bbox.xmax - select_bbox.xmin + 1) * (select_bbox.ymax - select_bbox.ymin + 1));
        float x1 = static_cast<float>(select_bbox.xmin);
        float y1 = static_cast<float>(select_bbox.ymin);
        float x2 = static_cast<float>(select_bbox.xmax);
        float y2 = static_cast<float>(select_bbox.ymax);

        select_idx++;
#pragma omp parallel for num_threads(threads_num)
        for (int32_t i = select_idx; i < num_bbox; i++) {
            if (mask_merged[i] == 1)
                continue;

            FaceBox & bbox_i = bboxes[i].bbox;
            float x = std::max<float>(x1, static_cast<float>(bbox_i.xmin));
            float y = std::max<float>(y1, static_cast<float>(bbox_i.ymin));
            float w = std::min<float>(x2, static_cast<float>(bbox_i.xmax)) - x + 1;
            float h = std::min<float>(y2, static_cast<float>(bbox_i.ymax)) - y + 1;
            if (w <= 0 || h <= 0)
                continue;

            float area2 = static_cast<float>((bbox_i.xmax - bbox_i.xmin + 1) * (bbox_i.ymax - bbox_i.ymin + 1));
            float area_intersect = w * h;

            switch (methodType) {
            case 'u':
                if (static_cast<float>(area_intersect) / (area1 + area2 - area_intersect) > thresh)
                    mask_merged[i] = 1;
                break;
            case 'm':
                if (static_cast<float>(area_intersect) / std::min(area1, area2) > thresh)
                    mask_merged[i] = 1;
                break;
            default:
                break;
            }
        }
    }
    return bboxes_nms;
}

void MtcnnDetector::BBoxRegression(vector<FaceInfo>& bboxes) {

#pragma omp parallel for num_threads(threads_num)
    for (size_t i = 0; i < bboxes.size(); ++i) {
        FaceBox &bbox = bboxes[i].bbox;
        float *bbox_reg = bboxes[i].bbox_reg;
        float w = bbox.xmax - bbox.xmin + 1;
        float h = bbox.ymax - bbox.ymin + 1;
        bbox.xmin += bbox_reg[0] * w;
        bbox.ymin += bbox_reg[1] * h;
        bbox.xmax += bbox_reg[2] * w;
        bbox.ymax += bbox_reg[3] * h;
    }
}

//边界框回归填充函数
void MtcnnDetector::BBoxPad(std::vector<FaceInfo>& bboxes, int width, int height) {

#pragma omp parallel for num_threads(threads_num)
    for (size_t i = 0; i < bboxes.size(); ++i) {
        FaceBox &bbox = bboxes[i].bbox;
        bbox.xmin = round(std::max(bbox.xmin, 0.f));
        bbox.ymin = round(std::max(bbox.ymin, 0.f));
        bbox.xmax = round(std::min(bbox.xmax, width - 1.f));
        bbox.ymax = round(std::min(bbox.ymax, height - 1.f));
    }
}

void MtcnnDetector::BBoxPadSquare(std::vector<FaceInfo>& bboxes, int width, int height) {

#pragma omp parallel for num_threads(threads_num)
    for (size_t i = 0; i < bboxes.size(); ++i) {
        FaceBox &bbox = bboxes[i].bbox;
        float w = bbox.xmax - bbox.xmin + 1;
        float h = bbox.ymax - bbox.ymin + 1;
        float side = h>w ? h : w;
        bbox.xmin = round(std::max(bbox.xmin + (w - side)*0.5f, 0.f));

        bbox.ymin = round(std::max(bbox.ymin + (h - side)*0.5f, 0.f));
        bbox.xmax = round(std::min(bbox.xmin + side - 1, width - 1.f));
        bbox.ymax = round(std::min(bbox.ymin + side - 1, height - 1.f));
    }
}

/** 根据置信度和边界框回归量从原图得到对应的人脸框
 * @brief MtcnnDetector::GenerateBBox
 * @param confidence
 * @param reg_box
 * @param scale
 * @param thresh
 */
void MtcnnDetector::GenerateBBox(Blob<float>* confidence, Blob<float>* reg_box,
    float scale, float thresh) {

    int feature_map_w_ = confidence->width();
    int feature_map_h_ = confidence->height();
    int spatical_size = feature_map_w_*feature_map_h_;
    const float* confidence_data = confidence->cpu_data() + spatical_size;
    const float* reg_data = reg_box->cpu_data();
    candidate_boxes_.clear();
    for (int i = 0; i<spatical_size; i++) {
        if (confidence_data[i] >= thresh) {

            int y = i / feature_map_w_;
            int x = i - feature_map_w_ * y;
            FaceInfo faceInfo;
            FaceBox &faceBox = faceInfo.bbox;

            faceBox.xmin = (float)(x * pnet_stride) / scale;
            faceBox.ymin = (float)(y * pnet_stride) / scale;
            faceBox.xmax = (float)(x * pnet_stride + pnet_cell_size - 1.f) / scale;
            faceBox.ymax = (float)(y * pnet_stride + pnet_cell_size - 1.f) / scale;

            faceInfo.bbox_reg[0] = reg_data[i];
            faceInfo.bbox_reg[1] = reg_data[i + spatical_size];
            faceInfo.bbox_reg[2] = reg_data[i + 2 * spatical_size];
            faceInfo.bbox_reg[3] = reg_data[i + 3 * spatical_size];

            faceBox.score = confidence_data[i];
            candidate_boxes_.push_back(faceInfo);
        }
    }
}


vector<FaceInfo> MtcnnDetector::ProposalNet(const cv::Mat& img, int minSize, float threshold, float factor) {

    int width = img.cols;
    int height = img.rows;

    float scale = 12.f / minSize;   //计算尺度来进行图像金字塔操作
    float minWH = std::min(height, width) *scale; // 原图先进行缩放
    std::vector<float> scales;
    while (minWH >= 12) {
        //不断迭代 找出所有的缩放尺度 最大尺度为整张图都是人脸 如果预先知道人脸想对于图像的大小 是否可以直接进行计算得到factor的值
        //固定的factor和minSize 则得到的图像金字塔的尺度应该是一致的 所以这边并非需要每次都进行计算 可以优化
        scales.push_back(scale);
        minWH *= factor;
        scale *= factor;
    }
    cv::Mat resized;

    Blob<float>* input_layer = PNet_->input_blobs()[0];
    total_boxes_.clear();

    for (int i = 0; i < scales.size(); i++) {
        //每次缩放一次进行一次检测
        int ws = (int)std::ceil(width*scales[i]);
        int hs = (int)std::ceil(height*scales[i]);
        cv::resize(img, resized, cv::Size(ws, hs), 0, 0, cv::INTER_LINEAR);
        input_layer->Reshape(1, 3, hs, ws);
        PNet_->Reshape();

        float * input_data = input_layer->mutable_cpu_data();
        cv::Vec3f * img_data = (cv::Vec3f *)resized.data;
        int spatial_size = ws* hs;
        for (int k = 0; k < spatial_size; ++k) {
            input_data[k] = img_data[k][0];
            input_data[k + spatial_size] = img_data[k][1];
            input_data[k + 2 * spatial_size] = img_data[k][2];
        }

        PNet_->Forward();

        Blob<float>* confidence = PNet_->blob_by_name("prob1").get();
        Blob<float>* reg = PNet_->blob_by_name("conv4-2").get();
        GenerateBBox(confidence, reg, scales[i], threshold);
        std::vector<FaceInfo> bboxes_nms = NMS(candidate_boxes_, 0.5, 'u');
        if (bboxes_nms.size()>0) {
            total_boxes_.insert(total_boxes_.end(), bboxes_nms.begin(), bboxes_nms.end());
        }
    }
    int num_box = (int)total_boxes_.size();
    vector<FaceInfo> res_boxes;
    if (num_box != 0) {
        res_boxes = NMS(total_boxes_, 0.5f, 'u');
        BBoxRegression(res_boxes);
        BBoxPadSquare(res_boxes, width, height);
    }
    return res_boxes;
}

std::vector<FaceInfo> MtcnnDetector::NextStage(const cv::Mat& image, std::vector<FaceInfo> &pre_stage_res, int input_w, int input_h, int stage_num, const float threshold) {
    std::vector<FaceInfo> res;
    int batch_size = (int)pre_stage_res.size();
    if (batch_size == 0)
        return res;
    Blob<float>* input_layer = nullptr;
    Blob<float>* confidence = nullptr;
    Blob<float>* reg_box = nullptr;
    Blob<float>* reg_landmark = nullptr;

    switch (stage_num) {
    case 2: {
        input_layer = RNet_->input_blobs()[0];
        input_layer->Reshape(batch_size, 3, input_h, input_w);
        RNet_->Reshape();
    }break;
    case 3: {
        input_layer = ONet_->input_blobs()[0];
        input_layer->Reshape(batch_size, 3, input_h, input_w);
        ONet_->Reshape();
    }break;
    default:
        return res;
        break;
    }
    float * input_data = input_layer->mutable_cpu_data();
    int spatial_size = input_h*input_w;

#pragma omp parallel for num_threads(threads_num)
    for (int n = 0; n < batch_size; ++n) {
        FaceBox &box = pre_stage_res[n].bbox;
        cv::Mat roi = image(cv::Rect(cv::Point((int)box.xmin, (int)box.ymin), cv::Point((int)box.xmax, (int)box.ymax))).clone();
        resize(roi, roi, cv::Size(input_w, input_h));
        float *input_data_n = input_data + input_layer->offset(n);
        cv::Vec3f *roi_data = (cv::Vec3f *)roi.data;
        CHECK_EQ(roi.isContinuous(), true);
        for (int k = 0; k < spatial_size; ++k) {
            input_data_n[k] = roi_data[k][0];
            input_data_n[k + spatial_size] = roi_data[k][1];
            input_data_n[k + 2 * spatial_size] = roi_data[k][2];
        }
    }
    switch (stage_num) {
    case 2: {
        RNet_->Forward();
        confidence = RNet_->blob_by_name("prob1").get();
        reg_box = RNet_->blob_by_name("conv5-2").get();
    }break;
    case 3: {
        ONet_->Forward();
        confidence = ONet_->blob_by_name("prob1").get();
        reg_box = ONet_->blob_by_name("conv6-2").get();
        reg_landmark = ONet_->blob_by_name("conv6-3").get();
    }break;
    }
    const float* confidence_data = confidence->cpu_data();
    const float* reg_data = reg_box->cpu_data();
    const float* landmark_data = nullptr;
    if (reg_landmark) {
        landmark_data = reg_landmark->cpu_data();
    }
    for (int k = 0; k < batch_size; ++k) {
        if (confidence_data[2 * k + 1] >= threshold) {
            FaceInfo info;
            info.bbox.score = confidence_data[2 * k + 1];
            info.bbox.xmin = pre_stage_res[k].bbox.xmin;
            info.bbox.ymin = pre_stage_res[k].bbox.ymin;
            info.bbox.xmax = pre_stage_res[k].bbox.xmax;
            info.bbox.ymax = pre_stage_res[k].bbox.ymax;
            for (int i = 0; i < 4; ++i) {
                info.bbox_reg[i] = reg_data[4 * k + i];
            }
            if (reg_landmark) {
                float w = info.bbox.xmax - info.bbox.xmin + 1.f;
                float h = info.bbox.ymax - info.bbox.ymin + 1.f;
                for (int i = 0; i < 5; ++i){
                    info.landmark[2 * i] = landmark_data[10 * k + 2 * i] * w + info.bbox.xmin;
                    info.landmark[2 * i + 1] = landmark_data[10 * k + 2 * i + 1] * h + info.bbox.ymin;
                }
            }
            res.push_back(info);
        }
    }
    return res;
}

void MtcnnDetector::nmsTwoBoxs(std::vector<FaceInfo> &firstBBox, std::vector<FaceInfo> &secondBBox,
                               float threshold, char methodType){

    if(firstBBox.empty()){
        return;
    }
    sort(firstBBox.begin(), firstBBox.end(), CompareBBox);
    float IOU = 0;
    float maxX = 0;
    float maxY = 0;
    float minX = 0;
    float minY = 0;
    float area1 = 0;
    float area2 = 0;
    for (std::vector<FaceInfo>::iterator ity = secondBBox.begin(); ity != secondBBox.end(); ity++) {
        for (std::vector<FaceInfo>::iterator itx = firstBBox.begin(); itx != firstBBox.end();) {
            size_t i = static_cast<size_t>(itx - firstBBox.begin());
            size_t j = static_cast<size_t>(ity - secondBBox.begin());
            maxX = std::max(firstBBox.at(i).bbox.xmin, secondBBox.at(j).bbox.xmin);
            maxY = std::max(firstBBox.at(i).bbox.ymin, secondBBox.at(j).bbox.ymin);
            minX = std::min(firstBBox.at(i).bbox.xmax, secondBBox.at(j).bbox.xmax);
            minY = std::min(firstBBox.at(i).bbox.ymax, secondBBox.at(j).bbox.ymax);

            maxX = ((minX - maxX + 1) > 0) ? (minX - maxX + 1) : 0;
            maxY = ((minY - maxY + 1) > 0) ? (minY - maxY + 1) : 0;

            IOU = maxX * maxY;
            area1 = (firstBBox.at(i).bbox.ymax - firstBBox.at(i).bbox.ymin)
                    * (firstBBox.at(i).bbox.xmax - firstBBox.at(i).bbox.xmin);
            area2 = (secondBBox.at(j).bbox.ymax - secondBBox.at(j).bbox.ymin)
                    * (secondBBox.at(j).bbox.xmax - secondBBox.at(j).bbox.xmin);

            switch (methodType) {
            case 'u':
                IOU = IOU / (area1 + area2 - IOU);
                break;
            case 'm':
                IOU = IOU / ((area1 < area2) ? area1 : area2);
                break;
            }
            if(IOU > threshold && firstBBox.at(i).bbox.score > secondBBox.at(j).bbox.score)
                itx = firstBBox.erase(itx);
            else{
                itx++;
            }
        }
    }
}

std::vector<FaceInfo> MtcnnDetector::ProposalNet(const cv::Mat& img, const float scale, int minSize, float threshold, float factor) {

    cv::Mat resized;
    int width = img.cols;
    int height = img.rows;

    Blob<float>* input_layer = PNet_->input_blobs()[0];

    //每次缩放一次进行一次检测
    int ws = (int)std::ceil(width * scale);
    int hs = (int)std::ceil(height * scale);
    cv::resize(img, resized, cv::Size(ws, hs), 0, 0, cv::INTER_LINEAR);
    input_layer->Reshape(1, 3, hs, ws);
    PNet_->Reshape();
    float * input_data = input_layer->mutable_cpu_data();
    cv::Vec3f * img_data = (cv::Vec3f *)resized.data;
    int spatial_size = ws* hs;
    for (int k = 0; k < spatial_size; ++k) {
        input_data[k] = img_data[k][0];
        input_data[k + spatial_size] = img_data[k][1];
        input_data[k + 2 * spatial_size] = img_data[k][2];
    }
    PNet_->Forward();

    Blob<float>* confidence = PNet_->blob_by_name("prob1").get();
    Blob<float>* reg = PNet_->blob_by_name("conv4-2").get();

    GenerateBBox(confidence, reg, scale, threshold);
    std::vector<FaceInfo> bboxes_nms = NMS(candidate_boxes_, 0.5, 'u');

    if (bboxes_nms.size()>0) {
        firstBbox_.insert(firstBbox_.end(), bboxes_nms.begin(), bboxes_nms.end());
    }

    candidate_boxes_.clear();
    firstBbox_ = NMS(firstBbox_, threshold, 'u');
    nmsTwoBoxs(firstBbox_, firstPreviousBbox_, threshold, 'u');
    firstPreviousBbox_.insert(firstPreviousBbox_.end(), firstBbox_.begin(), firstBbox_.end());

    int num_box = (int)firstBbox_.size();

    //refine
    if (num_box != 0) {
        BBoxRegression(firstBbox_);
        BBoxPadSquare(firstBbox_, width, height);
    }
    return firstBbox_;
}

void MtcnnDetector::extractMaxFace(std::vector<FaceInfo>& boundingBox_){
    if (boundingBox_.empty()) {
        return;
    }
    sort(boundingBox_.begin(), boundingBox_.end(), cmpArea);
    for (std::vector<FaceInfo>::iterator itx = boundingBox_.begin() + 1; itx != boundingBox_.end();) {
        itx = boundingBox_.erase(itx);
    }
}

std::vector<FaceInfo> MtcnnDetector::DetectMaxFace(const cv::Mat& image, const int stage){

    vector<FaceInfo> pnet_res;
    vector<FaceInfo> rnet_res;
    vector<FaceInfo> onet_res;

    firstPreviousBbox_.clear();
    secondPreviousBbox_.clear();
    firstBbox_.clear();
    secondBbox_.clear();

    const float* threshold = this->threshold;
    const float factor = this->factor;
    const int minSize = this->minSize;

    cv::Mat imageFloat;
    image.convertTo(imageFloat, CV_32FC1);

    imageFloat = (imageFloat - mean_val) * std_val;

    int width = image.cols;
    int height = image.rows;

    float scale = 12.f / minSize;   //计算尺度来进行图像金字塔操作
    float minWH = std::min(height, width) *scale; // 原图先进行缩放
    std::vector<float> scales;
    if(scaleGenerateFlag == true) {
        while (minWH >= 12) {
            //不断迭代 找出所有的缩放尺度 最大尺度为整张图都是人脸 如果预先知道人脸想对于图像的大小 是否可以直接进行计算得到factor的值
            //固定的factor和minSize 则得到的图像金字塔的尺度应该是一致的 所以这边并非需要每次都进行计算 可以优化
            scales.push_back(scale);
            minWH *= factor;
            scale *= factor;
        }
    }else{
        scales.push_back(_scale);
    }

    sort(scales.begin(), scales.end());
    for(size_t i = 0; i < scales.size(); i++) {
        if (stage >= 1){
            pnet_res = ProposalNet(imageFloat, scales[i], minSize, threshold[0], factor);
        }
        if (stage >= 2 && pnet_res.size()>0){
            if (pnet_max_detect_num < (int)pnet_res.size()){
                pnet_res.resize(pnet_max_detect_num);
            }
            vector<FaceInfo> res = NextStage(imageFloat, pnet_res, 24, 24, 2, threshold[1]);
            rnet_res.insert(rnet_res.end(), res.begin(), res.end());

            secondBbox_ = NMS(rnet_res, 0.5f, 'u');
            nmsTwoBoxs(secondBbox_, secondPreviousBbox_, threshold[0], 'u');
            secondPreviousBbox_.insert(secondPreviousBbox_.end(), secondBbox_.begin(), secondBbox_.end());
            BBoxRegression(secondBbox_);
            BBoxPadSquare(secondBbox_, imageFloat.cols, imageFloat.rows);
            rnet_res = secondBbox_;
        }
        if (stage >= 3 && rnet_res.size()>0){
            vector<FaceInfo> res = NextStage(imageFloat, rnet_res, 48, 48, 3, threshold[2]);
            onet_res.insert(onet_res.end(), res.begin(), res.end());
            if (onet_res.size() < 1) {
                    firstBbox_.clear();
                    secondBbox_.clear();
                    continue;
            }
            BBoxRegression(onet_res);
            onet_res = NMS(onet_res, 0.5f, 'm');
            BBoxPad(onet_res, imageFloat.cols, imageFloat.rows);
            if (onet_res.size() > 0) {
                extractMaxFace(onet_res);
                break;
            }
        }
    }

    if (stage == 1){
        return pnet_res;
    }
    else if (stage == 2){
        return rnet_res;
    }
    else if (stage == 3){
        autoSet(onet_res, image);       //自适应图像金字塔参数
        return onet_res;
    }
    else{
        return onet_res;
    }
}

vector<FaceInfo> MtcnnDetector::Detect(const cv::Mat& image, const int stage) {

    vector<FaceInfo> pnet_res;
    vector<FaceInfo> rnet_res;
    vector<FaceInfo> onet_res;

    const float* threshold = this->threshold;
    const float factor = this->factor;
    const int minSize = this->minSize;

    cv::Mat imageFloat;
    image.convertTo(imageFloat, CV_32FC1);

    imageFloat = (imageFloat - mean_val) * std_val;

    if (stage >= 1){
        pnet_res = ProposalNet(imageFloat, minSize, threshold[0], factor);
    }
    if (stage >= 2 && pnet_res.size()>0){
        if (pnet_max_detect_num < (int)pnet_res.size()){
            pnet_res.resize(pnet_max_detect_num);
        }
        int num = (int)pnet_res.size();
        int size = (int)ceil(1.f*num / step_size);
        for (int iter = 0; iter < size; ++iter){
            int start = iter*step_size;
            int end = std::min(start + step_size, num);
            vector<FaceInfo> input(pnet_res.begin() + start, pnet_res.begin() + end);
            vector<FaceInfo> res = NextStage(imageFloat, input, 24, 24, 2, threshold[1]);
            rnet_res.insert(rnet_res.end(), res.begin(), res.end());
        }
        rnet_res = NMS(rnet_res, 0.5f, 'u');
        BBoxRegression(rnet_res);
        BBoxPadSquare(rnet_res, imageFloat.cols, imageFloat.rows);

    }
    if (stage >= 3 && rnet_res.size()>0){
        int num = (int)rnet_res.size();
        int size = (int)ceil(1.f*num / step_size);
        for (int iter = 0; iter < size; ++iter){
            int start = iter*step_size;
            int end = std::min(start + step_size, num);
            vector<FaceInfo> input(rnet_res.begin() + start, rnet_res.begin() + end);
            vector<FaceInfo> res = NextStage(imageFloat, input, 48, 48, 3, threshold[2]);
            onet_res.insert(onet_res.end(), res.begin(), res.end());
        }
        BBoxRegression(onet_res);
        onet_res = NMS(onet_res, 0.5f, 'm');
        BBoxPad(onet_res, imageFloat.cols, imageFloat.rows);

    }
    if (stage == 1){
        return pnet_res;
    }
    else if (stage == 2){
        return rnet_res;
    }
    else if (stage == 3){
        return onet_res;
    }
    else{
        return onet_res;
    }
}

void MtcnnDetector::autoSet(std::vector<FaceInfo>& faceInfo, const cv::Mat& image) {

    if(faceInfo.size() > 0){
        int w = (int) (faceInfo[0].bbox.xmax - faceInfo[0].bbox.xmin + 1);
        int h = (int) (faceInfo[0].bbox.ymax - faceInfo[0].bbox.ymin + 1);
        float scale = 12.f / minSize;   //计算尺度来进行图像金字塔操作
        float minWH = std::min(w, h) * scale; // 原图先进行缩放
        while(minWH >= 12.f){
            minWH *= factor;
            scale *= factor;
        }
        _scale = scale;
        scaleGenerateFlag = false;
    }else{
        scaleGenerateFlag = true;
    }
}

void MtcnnDetector::drawResult(std::vector<FaceInfo>& faceInfo, cv::Mat& image){

    for (int i = 0; i < faceInfo.size(); i++) {
        int x = (int) faceInfo[i].bbox.xmin;
        int y = (int) faceInfo[i].bbox.ymin;
        int w = (int) (faceInfo[i].bbox.xmax - faceInfo[i].bbox.xmin + 1);
        int h = (int) (faceInfo[i].bbox.ymax - faceInfo[i].bbox.ymin + 1);
        cv::rectangle(image, cv::Rect(x, y, w, h), cv::Scalar(255, 0, 0), 2);
        //标记点
        for(int j = 0; j < 5; j++) {
            cv::circle(image,cv::Point(faceInfo[i].landmark[2 * j],faceInfo[i].landmark[2 * j + 1]), 1, cv::Scalar(255,255,0),2);
        }
        cv::putText(image, cv::format("%.4f",faceInfo[i].bbox.score), cv::Point(x, y), cv::FONT_HERSHEY_SCRIPT_SIMPLEX, 1, cv::Scalar(0,0,255));

    }
}
