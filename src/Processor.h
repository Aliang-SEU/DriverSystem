#ifndef PROCESSOR_H
#define PROCESSOR_H

#define LANDMARKDETECTOR 1

#include <QObject>
#include <QImage>
#include <QThread>

#include <MtcnnDetector.h>
#include <MouthRecognition.h>
#include <VideoCaptureSource.h>
#include <CaptureSequence.h>
#include <PoseEstimator.h>
#include <KalmanStabilizer.h>
#include <EyeRecognition.h>
#include <SpecialVideoRecord.h>
#include <CommonVideoRecord.h>

#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>

#if LANDMARKDETECTOR==1
#include <LandmarkWithPose.h>
#elif LANDMARKDETECTOR==2
#include <Landmark.h>
#elif  LANDMARKDETECTOR==3
#include <LandmarVanilla.h>
#endif

typedef struct FrameInfo{
    cv::Mat image;  //每一帧的图像
    cv::Mat resizedImage;  //每一帧的图像
    cv::Mat processedImage; //处理之后的人脸图像
    std::vector<FaceInfo> faceInfo; //人脸信息
    cv::Rect2f originFacebbox;
    cv::Rect2f facebbox;    //原图像中对应的人脸框
    std::vector<cv::Point> facePoints;  //MTCNN对应的特征点
    LandmarkAndPose landmarkAndPose; //特征点与姿态角的原始数据
    std::vector<cv::Point2f> landmarkPoints;//关键点对应原图像中的坐标
    cv::Point2f leftEyePoint,rightEyePoint;
    std::vector<cv::Mat_<double>> vec; //向量维度
    cv::Rect2f leftEyeBBox;
    cv::Rect2f rightEyeBBox;
    enum EyeState leftEye;
    enum EyeState rightEye;
    enum EyeState mouth;
    float mouthAlpha;
}FrameInfo;

class Processor : public QObject {
    Q_OBJECT

public slots:
    bool processNextFrame(cv::Mat image);
public:
    Processor(float fps=25.0, QObject *parent = nullptr);
    bool getNextFrame();
    bool openWebcam(int height=480, int width=640, int deviceId=1);
    bool readVideoCapture(int deviceId);
    bool openVideoFile(const std::string videoFile);
    bool detectFace();
    bool detectLandmark();
    bool estimatorPose();
    bool detectEyeState();
    bool detectMouthState();

    cv::Mat getProcessedImage();
    FrameInfo getFrameInfo();

public slots:
    bool reset();
    bool resetAll();
    void getShowProcessFLag(bool flag);

private:
    QImage convertCvMatToQImage(const cv::Mat &matrix);
    void drawFace();
    void drawLandmark();
    void drawFacePoints();
    void drawAnnotationBox();
    void drawOriginFace();
    void drawEyeState();
    void drawPose();
    cv::Rect refineBBox(cv::Mat& image, std::vector<FaceInfo>& faceInfo);
    cv::Rect backScale(cv::Rect inputRect, int Scale);

private:
    std::shared_ptr<Utilities::CaptureSequence> captureSequence; //视频源
    std::shared_ptr<MtcnnDetector> faceDetector;                //人脸检测器
#if LANDMARKDETECTOR==1
    std::shared_ptr<LandmarkWithPose> landmarkWithPose;
#elif LANDMARKDETECTOR==2
    std::shared_ptr<Landmark> landmarkWithPose;          //特征点检测器
#elif  LANDMARKDETECTOR==3
    std::shared_ptr<LandmarVanilla> landmarkWithPose;          //特征点检测器
#endif
    std::shared_ptr<PoseEstimator> poseEstimator;                //姿态计算器
    std::vector<std::shared_ptr<KalmanStabilizer>> poseStabilizers;  //卡尔曼滤波器
    std::vector<std::shared_ptr<KalmanStabilizer>> poseEstimatorStabilizers;  //卡尔曼滤波器
    std::shared_ptr<EyeRecognition> eyeRecognition; //眼睛检测器
    std::shared_ptr<MouthRecognition> mouthRecognition; //MouthDetector

public:
    std::shared_ptr<SpecialVideoRecord> videoRecord;
    std::shared_ptr<CommonVideoRecord> commonVideoRecord;

private:
    FrameInfo frameInfo;
    const int resizedScale = 1;
    cv::Size resizedSize;
    float fps;
    int resetFlag;
    bool showProcessFLag = true;
    std::shared_ptr<QThread> videoRecordThread;

signals:
  void imageRecord(cv::Mat);
  void frame(cv::Mat image);
  void eyeFatigue();
  void mouthFatigue();
  void faceSingnal(FrameInfo frameInfo);
};

#endif // PROCESSOR_H
