#include <CameraCaptureThread.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>
#include <QImage>
#include <VideoCaptureSource.h>
#include <QCameraInfo>

CameraTask::CameraTask(){
}

CameraTask::~CameraTask(){
    //Leave camera and videoFrame alone, they will be destroyed elsewhere
}

bool CameraTask::setCapture(cv::VideoCapture capture){
    this->running = true;
    this->capture = capture;
    this->width = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_WIDTH));
    this->height = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_HEIGHT));
}

void CameraTask::stop(){
    running = false;
}

void CameraTask::doWork(){
    while(running && capture.isOpened()){
        cv::Mat cameraFrame;
        capture.read(cameraFrame);
        emit imageReady(cameraFrame);
    }
    if (capture.isOpened())
        capture.release();
}

void CameraTask::doWorkForFile(){
    if(capture.isOpened()){
        cv::Mat cameraFrame;
        capture.read(cameraFrame);
         cv::resize(cameraFrame,cameraFrame,cv::Size(640,480));
        emit imageReady(cameraFrame);
    }
}

//*********************************************************************
/**其他
 * @brief CameraCaptureThread::CameraCaptureThread
 * @param parent
 */

CameraCaptureThread::CameraCaptureThread(QObject *parent)
    : QObject(parent){
  task = std::make_shared<CameraTask>();
  task->moveToThread(&workerThread);
  QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(captureFrame()));
  QObject::connect(&workerThread, SIGNAL(started()), task.get(), SLOT(doWork()));
  QObject::connect(task.get(), SIGNAL(imageReady(cv::Mat)),
                   this, SIGNAL(imageReady(cv::Mat)));
}

CameraCaptureThread::~CameraCaptureThread(){
    stop();
}

void CameraCaptureThread::start(){
    workerThread.start();
}

void CameraCaptureThread::stop(){
    if(task.get() != nullptr){
        task->stop();
    }
    if(workerThread.isRunning()){
        workerThread.quit();
        workerThread.wait();
        //此处确保线程退出 应该已经释放了capture
    }
    if(timer.isActive()){
        timer.stop();
    }
}

/** 读取摄像头设备
 * @brief CameraCaptureThread::readCamera
 * @param deviceId
 */
void CameraCaptureThread::readCamera(int deviceId) {

  stop();
  cv::VideoCapture camera;
  camera.open(deviceId);
  if (!camera.isOpened()) {
    qCritical() << "摄像头打开失败!";
    return;
  }else{
      //set camera prop
      camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
      camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
      qDebug() << "摄像头打开成功";
      task->setCapture(camera);
      //线程启动就触发
      this->start();
  }
}

void CameraCaptureThread::readVideoFiles(const QString& videoFile) {
  //首先关闭上次的资源文件
  stop();
  qDebug() << "打开视频文件";
  qDebug() << videoFile;
  if (!cap.open(videoFile.toStdString())) {
    qCritical() << "打开视频文件失败!";
    return;
  }else{
      qDebug() << "视频文件打开成功";
      float fps = static_cast<float>(cap.get(CV_CAP_PROP_FPS));
      timer.start(int(1000 / fps));
  }
}

void CameraCaptureThread::captureFrame() {
  cv::Mat frame;
  if (!cap.read(frame)) {
    return;
  }
  //cv::resize(frame,frame,cv::Size(640,480));
  emit this->imageReady(frame);
}

/** 获取设备上的所有的摄像头
 * @brief CameraCaptureThread::getCameraList
 * @return
 */
QStringList CameraCaptureThread::getCameraList(){
    QStringList deviceList;
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for(const auto& cameraInfo : cameras){
        QString device;
        device += cameraInfo.deviceName();
        device += " - ";
        device += cameraInfo.description();
        deviceList << device;
    }
    qDebug() << deviceList;
    return deviceList;
}

