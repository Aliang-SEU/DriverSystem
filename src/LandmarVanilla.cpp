#include "LandmarVanilla.h"

LandmarVanilla::LandmarVanilla(){
    Caffe::set_mode(Caffe::GPU);
    net.reset(new Net<float>(this->network, TEST));
    net->CopyTrainedLayersFrom(this->weights);
    Blob<float>* input_layer = net->input_blobs()[0];
    this->input_size = cv::Size(input_layer->width(), input_layer->height());
    this->num_channels_ = input_layer->channels();
}

LandmarkAndPose LandmarVanilla::getPredict(cv::Mat& img){

    cv::Mat img2;
    cv::cvtColor(img, img2, CV_BGR2GRAY);
    img2.convertTo(img2, CV_32FC1);
    cv::resize(img2, img2, cv::Size(40, 40), 0, 0, cv::INTER_CUBIC);

    cv::Mat tmp_mean, tmp_sd;
    cv::meanStdDev(img2, tmp_mean, tmp_sd);
    double m = 0, sd = 0;
    m = tmp_mean.at<double>(0, 0);  //均值
    sd = tmp_sd.at<double>(0, 0);   //标准差

    img2 = (img2 - m) / (0.000001f + sd);
    if(img2.channels() * img2.rows *img2.cols != net->input_blobs()[0]->count())
        LOG(FATAL) << "Incorrect size!\n";

    std::vector<Blob<float>*> in_blobs = net->input_blobs();
    float *data = nullptr;

    //prepare data into array
    data = (float*)malloc( img2.rows * img2.cols * sizeof(float));

    int pix_count = 0;
    for(int i = 0; i < img2.rows; i++) {
        float* pData=img2.ptr<float>(i);
        for(int j = 0; j < img2.cols; j++) {
            data[pix_count++] = pData[j];
        }
    }
    in_blobs[0]->set_cpu_data(data);

    net->Forward();
    const boost::shared_ptr<Blob<float> > feature_blob = net->blob_by_name("Dense2");//获取该层特征
    float feat_dim = feature_blob->count() / feature_blob->num();//计算特征维度
    const float* data_ptr = (const float *)feature_blob->cpu_data();//特征块数据

    LandmarkAndPose landmarkAndPose;

    for (int i = 0; i < feat_dim; i++) {
        landmarkAndPose.landmark.push_back(*(data_ptr + i));
    }
    delete data;
    return landmarkAndPose;
}
