#include "CommonVideoRecord.h"

CommonVideoRecord::CommonVideoRecord(){
    fileName = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss");
    nameIdx = 1;
    httpService = std::make_shared<HttpService>();
    QObject::connect(this, SIGNAL(uploadFile(QString, QString)), httpService.get(), SLOT(uploadVideoFile(QString, QString)));
}


void CommonVideoRecord::videoRecord(cv::Mat image){
    if(!videoWriter.isOpened()){
        filePath = fileName.toStdString() + "-" + std::to_string(nameIdx) + ".avi";
        videoWriter = cv::VideoWriter(filePath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30.0, image.size());
        idx = 0;
    }else{
        videoWriter << image;
        idx++;
        qint64 end = 30 * 60 * 5;
        if(idx == end){
           idx = 0;
           videoWriter.release();
           nameIdx++;
           emit uploadFile(QString(filePath.c_str()), QString("video"));
        }
    }
}
