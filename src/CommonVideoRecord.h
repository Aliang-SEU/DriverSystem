#ifndef COMMONVIDEORECORD_H
#define COMMONVIDEORECORD_H

#include<QObject>
#include<QDateTime>
#include<HttpService.h>
#include<opencv2/opencv.hpp>
#include<memory>

class CommonVideoRecord : public QObject{
    Q_OBJECT
public:
    explicit CommonVideoRecord();

public slots:
    void videoRecord(cv::Mat image);

private:
    cv::VideoWriter videoWriter;
    QString fileName;
    qint64 nameIdx;
    qint64 idx;
    std::shared_ptr<HttpService> httpService;
    std::string filePath;

signals:
    void uploadFile(QString, QString);

};

#endif // COMMONVIDEORECORD_H
