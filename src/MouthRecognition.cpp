#include <MouthRecognition.h>
#include <iostream>
#include <opencv2/imgproc.hpp>

MouthRecognition::MouthRecognition(float fps){
    outFile.open("mouthState.txt");
    this->fps = fps;
    this->flagCount = 0;
    this->threshAlpha = threshAlpha1;
    this->warningCount1 = static_cast<int>(this->fps * 1);
    this->warningCount2 = static_cast<int>(this->fps * 2);
    this->warningCount3 = static_cast<int>(this->fps * 5);
    this->totalCount = static_cast<int>(this->fps * 20);
}

MouthRecognition::~MouthRecognition() {
    outFile.close();
}

/**
 * @brief getDistance
 * @param p1
 * @param p2
 * @return
 */
float getDistance(cv::Point2f p1, cv::Point2f p2) {
    float res = static_cast<float>(std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2)));
    return res;
}

/** 人脸倾斜矫正2D(需要结合姿态估计计算3维情况下的人脸)
 * @brief MouthRecognition::correctPoint
 * @param theta
 * @param points
 */
void MouthRecognition::correctPoint(float theta, std::vector<cv::Point2f>& points) {
    cv::Point2f mouthCenter = (points[0]+ points[4]) / 2;
    double angle = static_cast<double>(theta) * 180.0 / CV_PI;
    cv::Mat rot_mat = getRotationMatrix2D(mouthCenter, angle, 1);
    for(size_t i = 0; i < points.size(); i++) {
        cv::Point2f p0;
        p0.x = rot_mat.ptr<float>(0)[0] * points[i].x + rot_mat.ptr<float>(0)[1] * points[i].y + rot_mat.ptr<float>(0)[2];
        p0.y = rot_mat.ptr<float>(1)[0] * points[i].x + rot_mat.ptr<float>(1)[1] * points[i].y + rot_mat.ptr<float>(1)[2];
        points[i] = p0;
    }
}


/** 计算人脸对应的张合度
 * @brief MouthRecognition::calculate
 * @param points
 */
float MouthRecognition::calculate(std::vector<cv::Point2f>& points) {

    //get innerMouth Points 60-67
    innerMouth.clear();

    for(size_t i = 0; i < 8; i++) {
        innerMouth.push_back(points[60 + i]);
    }

    //此处需要进行矫正
    float theta = static_cast<float>(atan2(static_cast<double>(innerMouth[4].y) - static_cast<double>(innerMouth[0].y),
                                            static_cast<double>(innerMouth[4].x) - static_cast<double>(innerMouth[0].x)));
    correctPoint(theta, innerMouth);

    float averageDistance = 0;
    for(size_t i = 0; i < 3; i++) {
        float temp = getDistance(innerMouth[1 + i], innerMouth[7 - i]);
        averageDistance += temp;
    }

    averageDistance /= 2.0f;
    H = averageDistance;
    L = getDistance(innerMouth[0], innerMouth[4]); //0 和 4 点分别为左右嘴角点
    alpha = H / (L + 0.00001f);

    if(alpha >= threshAlpha) {
        flagCount++;
    }else{
        flagCount = 0;
    }
    if(flagCount > warningCount2) {
        std::cout << "12312312" << std::endl;
        flagCount = 0;
    }
    if(flagCount > warningCount1) {
        this->threshAlpha = threshAlpha2;
    }
    alphaQueue.push_back(alpha);
    if(static_cast<int>(alphaQueue.size()) > totalCount){
        alphaQueue.pop_front();
        int count = 0;
        for(size_t i = 0 ; i < alphaQueue.size(); i++) {
            if(alphaQueue.at(i) > threshAlpha)
                count++;
        }
        if(count > warningCount3) {
            std::cout << "12312312" << std::endl;
            alphaQueue.clear();
        }
    }

    return alpha;
    /*for(int i = 0; i < 8; i++) {
        outFile << innerMouth[i].x << " " << innerMouth[i].y << std::endl;
    }
    outFile << alpha << std::endl;
    outFile << std::endl;
    std::cout<<"张合度:" << alpha << std::endl;
    */
}


float MouthRecognition::calculate(std::vector<cv::Point2f>& points, std::vector<float>& pose) {

    //get innerMouth Points 60-67
    innerMouth.clear();

    for(size_t i = 0; i < 8; i++) {
        innerMouth.push_back(points[60 + i]);
    }

    //此处需要进行矫正
    float theta = static_cast<float>(atan2(static_cast<double>(innerMouth[4].y) - static_cast<double>(innerMouth[0].y),
                                            static_cast<double>(innerMouth[4].x) - static_cast<double>(innerMouth[0].x)));
    correctPoint(theta, innerMouth);

    float averageDistance = 0;
    for(size_t i = 0; i < 3; i++) {
        float temp = getDistance(innerMouth[1 + i], innerMouth[7 - i]);
        averageDistance += temp;
    }

    averageDistance /= 3.0f;
    H = averageDistance;
    L = getDistance(innerMouth[0], innerMouth[4]); //0 和 4 点分别为左右嘴角点
    alpha = H / (L + 0.00001f);

//    //角度计算
//    float H1 = H / std::cos(pose[0]);
//    float L1 = L / std::cos(pose[1]);
//    float alpha1 = H1 / (L1 + 0.00001f);
//    outFile << alpha1 << std::endl;
    pose[0];
    return alpha;
}

bool MouthRecognition::mouthRecord(){
    if(alpha >= threshAlpha) {
        flagCount++;
    }else{
        flagCount = 0;
    }
    if(flagCount > warningCount2) {
        flagCount = 0;
        return true;
    }
    if(flagCount > warningCount1) {
        this->threshAlpha = threshAlpha2;
    }
    alphaQueue.push_back(alpha);
    if(static_cast<int>(alphaQueue.size()) > totalCount){
        alphaQueue.pop_front();
        int count = 0;
        for(size_t i = 0 ; i < alphaQueue.size(); i++) {
            if(alphaQueue.at(i) > threshAlpha)
                count++;
        }
        if(count > warningCount3) {
            alphaQueue.clear();
            return true;
        }
    }
    return false;
}
