#ifndef SPECIALVIDEORECORD_H
#define SPECIALVIDEORECORD_H

#include <QObject>
#include <QThread>

#include <HttpService.h>

#include <opencv2/opencv.hpp>

#include <deque>
#include <memory>

/** 应该持有数据库与数据库模块进行通信
 * @brief The VideoWriteTask class
 */
class VideoWriteTask : public QObject{
    Q_OBJECT

public:
    explicit VideoWriteTask(std::deque<cv::Mat> *frameQueue, float fps, QObject *parent = nullptr);

public slots:
    bool writeToLocal();

private:
    std::deque<cv::Mat> *frameQueue;
    const std::string videoPath= "../Videos/";
    float fps;
    std::shared_ptr<HttpService> httpService;

signals:
    void writeFinished();
    void progressBar(float);
    void uploadFile(QString, QString);
};

class SpecialVideoRecord : public QObject{
    Q_OBJECT
public:
    explicit SpecialVideoRecord(float fps, QObject *parent = nullptr);

private:
    std::deque<cv::Mat> frameQueue;
    float fps;
    int halfQueueSize;
    int fullQueueSize;
    const int timeRecord = 5;
    bool videoIsWriting = false;
    bool fatigueFlag = false;

    std::shared_ptr<QThread> videoWriteThread;
    std::shared_ptr<VideoWriteTask> videoWriteTask;

signals:
    void recordVideoSuccess();
    void recordVideoFail(std::string msg);
    void writeToLocal();
    void progress();
    void progressBar(float);
public:
    bool addFrame(cv::Mat image);
    void fatigueRecord();

public slots:
    void writeFinished();

};

#endif // SPECIALVIDEORECORD_H
