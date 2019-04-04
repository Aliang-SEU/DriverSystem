#include "SpecialVideoRecord.h"
#include <QTime>
#include <exception>
#include <QDebug>
#include <QString>

/** 共享图像队列，使用标志位进行并发控制
 * @brief VideoWriteTask::VideoWriteTask
 * @param frameQueue
 * @param fps
 * @param parent
 */
VideoWriteTask::VideoWriteTask(std::deque<cv::Mat> *frameQueue, float fps, QObject *parent)
    :QObject (parent){
    this->frameQueue = frameQueue;
    this->fps = fps;
    httpService = std::make_shared<HttpService>();
    QObject::connect(this, SIGNAL(uploadFile(QString, QString)), httpService.get(), SLOT(uploadVideoFile(QString, QString)));
    QObject::connect(httpService.get(), SIGNAL(progressBar(float)), this, SIGNAL(progressBar(float)));
}

/** 将图像写入到本地
 * @brief VideoWriteTask::writeToLocal
 * @return
 */
bool VideoWriteTask::writeToLocal(){
    QString fileName = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss");
    try{
        if(frameQueue->empty()){
            emit writeFinished();
            return false;
        }
        std::string filePath = videoPath + fileName.toStdString() + ".avi";
        cv::VideoWriter videoWriter(filePath,
                                    cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), static_cast<double>(this->fps),  (*frameQueue)[0].size());
        size_t frames = frameQueue->size();
        for( size_t idx = 0; idx < frames; idx++){
            videoWriter << (*frameQueue)[idx];
        }
        videoWriter.release();
        frameQueue->clear();
        emit uploadFile(QString(filePath.c_str()), QString("fatigue"));
        emit writeFinished();
        return true;
    }catch(std::exception& e){
        qDebug() << e.what();
    }
    return false;
}

/** 关键视频存储模块
 * @brief CommonVideoRecord::CommonVideoRecord
 * @param fps
 * @param parent
 */
SpecialVideoRecord::SpecialVideoRecord(float fps, QObject *parent)
    : QObject(parent){

    this->fps = fps;
    halfQueueSize = int(fps) * this->timeRecord;
    fullQueueSize = halfQueueSize * 2;
    videoWriteThread = std::make_shared<QThread>();
    videoWriteTask = std::make_shared<VideoWriteTask>(&frameQueue, this->fps);
    videoWriteTask->moveToThread(videoWriteThread.get());
    videoWriteThread->start();
    QObject::connect(this, SIGNAL(writeToLocal()), videoWriteTask.get(), SLOT(writeToLocal()));
    QObject::connect(videoWriteTask.get(), SIGNAL(writeFinished()), this, SLOT(writeFinished()), Qt::ConnectionType::DirectConnection);//此处在原线程直接处理
    QObject::connect(videoWriteTask.get(), SIGNAL(progressBar(float)), this, SIGNAL(progressBar(float)));
}

bool SpecialVideoRecord::addFrame(cv::Mat image){
    //首先判断当前是否在写图像
    if(!videoIsWriting){
        //正常情况的图像记录
        if(!fatigueFlag){
            if(static_cast<int>(this->frameQueue.size()) >= halfQueueSize) {
                frameQueue.pop_front();
            }
            frameQueue.push_back(image);
            return true;
        }else{
            if(static_cast<int>(this->frameQueue.size()) == fullQueueSize) {
                videoIsWriting = true;
                emit writeToLocal();
                return true;
            }else{
                frameQueue.push_back(image);
            }
            return true;
        }
    }else {
        return false;
    }
}

void SpecialVideoRecord::fatigueRecord(){
    if(this->fatigueFlag == false)
        this->fatigueFlag = true;
}

void SpecialVideoRecord::writeFinished(){
    fatigueFlag = false;
    videoIsWriting = false;
}
