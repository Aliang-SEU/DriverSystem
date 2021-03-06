#ifndef LANDMARKWITHPOSE_H
#define LANDMARKWITHPOSE_H

#include <caffe/caffe.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d.hpp>

#include <memory>

using namespace caffe;

typedef struct LandmarkAndPose {
    std::vector<float> landmark;
    std::vector<float> pose;
} LandmarkAndPose;

class LandmarkWithPose{

public:
    LandmarkWithPose();
    void setMean(const std::string& meanFile);
    void preprocess(cv::Mat& img, std::vector<cv::Mat>* input_channels);
    void wrapInputLayer(std::vector<cv::Mat>* input_channels);
    LandmarkAndPose getPredict(cv::Mat& image);
    void drawPose(cv::Mat& img, LandmarkAndPose& landmarkAndPose, float lineL);
private:
    const std::string network = "../model/landmarkWithPose/68point_with_pose.prototxt";
    const std::string param = "../model/landmarkWithPose/68point_with_pose.caffemodel";
    const std::string meanfile = "../model/landmarkWithPose/VGG_mean.binaryproto";

    std::shared_ptr<Net<float>> net;
    cv::Size inputSize;
    cv::Mat mean;
    int numChannels;
};

#endif // LANDMARKWITHPOSE_H
