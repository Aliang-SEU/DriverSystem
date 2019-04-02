#include "BetterVideoCapture.h"

BetterVideoCapture::BetterVideoCapture(){
    capture = new cv::VideoCapture();
}

BetterVideoCapture::~BetterVideoCapture(){
    delete capture;
}

bool BetterVideoCapture::open(int device){
    return capture->open(device);
}

double BetterVideoCapture::getProperty(int propIdx){
    return capture->get(propIdx);
}

bool BetterVideoCapture::setProperty(int propIdx,double propVal){
    return capture->set(propIdx,propVal);
}

bool BetterVideoCapture::grabFrame(){
    return capture->grab();
}

cv::Mat BetterVideoCapture::retrieveFrame(){
    capture->retrieve(rawImage);
    return rawImage;
}

bool BetterVideoCapture::isOpened() const{
    return capture->isOpened();
}
