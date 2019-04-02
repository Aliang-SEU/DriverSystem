#ifndef LANDMARVANILLA_H
#define LANDMARVANILLA_H

#include <caffe/caffe.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace caffe;

typedef struct LandmarkAndPose {
    std::vector<float> landmark;
    std::vector<float> pose;
} LandmarkAndPose;

class LandmarVanilla{

public:
    LandmarVanilla();
    LandmarkAndPose getPredict(cv::Mat& img);

private:
    const std::string network = "../model/landmark/vanilla.prototxt";
    const std::string weights = "../model/landmark/vanilla.caffemodel";

    std::shared_ptr<Net<float>> net;
    cv::Size  input_size;
    int num_channels_;

};

#endif // LANDMARVANILLA_H
