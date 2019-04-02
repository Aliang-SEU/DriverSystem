#ifndef BETTERVIDEOCAPTURE_H
#define BETTERVIDEOCAPTURE_H

#include<opencv2/videoio.hpp>

/**
 * @brief A better cv::VideoCapture for desktop and Android
 */
class BetterVideoCapture {

public:
    BetterVideoCapture();
    virtual ~BetterVideoCapture();

    bool open(int device);
    double getProperty(int propIdx);
    bool setProperty(int propIdx, double propVal);
    bool grabFrame();
    cv::Mat retrieveFrame();
    bool isOpened() const;

private:
    cv::VideoCapture* capture;
    cv::Mat rawImage;

};

#endif // BETTERVIDEOCAPTURE_H
