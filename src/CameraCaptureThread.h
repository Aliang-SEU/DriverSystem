#ifndef CAMERACAPTURETHREAD_H
#define CAMERACAPTURETHREAD_H

#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <opencv2/highgui/highgui.hpp>
#include <QThread>

#include <BetterVideoCapture.h>
#include <memory>

/**
 * @brief The CameraTask class
 */
class CameraTask : public QObject{
  Q_OBJECT
public:
    CameraTask();
    void stop();
    virtual ~CameraTask();
    bool setCapture(cv::VideoCapture capture);
private:
    int width;
    int height;
    cv::VideoCapture capture;
    bool running = false;
public slots:
    void doWork();
    void doWorkForFile();
signals:
    void imageReady(cv::Mat image);
};

/** 多线程的视频获取函数
 * @brief The CameraCaptureThread class
 */
class CameraCaptureThread : public QObject {
  Q_OBJECT

public:
  explicit CameraCaptureThread(QObject *parent = nullptr);
  virtual ~CameraCaptureThread();

public slots:
  void readVideoFiles(const QString& videoFile);
  void readCamera(int deviceId);
  void stop();
  void start();
  void captureFrame();
  QStringList getCameraList();

private:
  QThread workerThread;
  std::shared_ptr<CameraTask> task;            ///< The camera loop method and parameter container
  QTimer timer;
  cv::VideoCapture cap;

signals:
  void imageReady(QImage frame);
  void imageReady(cv::Mat frame);
  void resetProcessor();
};
#endif // CAMERACAPTURETHREAD_H
