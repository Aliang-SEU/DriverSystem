#include "HttpService.h"

HttpService::HttpService(){
    accessManager = std::make_shared<QNetworkAccessManager>();
    accessManager->setNetworkAccessible(QNetworkAccessManager::Accessible);
}

void HttpService::uploadVideoFile(QString filepath, QString folder){
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    file = new QFile(filepath);
    file->open(QIODevice::ReadOnly);
    QHttpPart videoPart;
    QString filename = filepath.split("/").last();
    videoPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("video/avi"));
    videoPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\";filename=" + filename));
    videoPart.setBodyDevice(file);

    QHttpPart pathPart;
    pathPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
    pathPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"folder\";"));
    pathPart.setBody(folder.toLatin1());
    //转换成byteArray进行网络传输
    file->setParent(multiPart);
    multiPart->append(videoPart);
    multiPart->append(pathPart);

    QString serviceUrl= serverIP + uploadService;
    QUrl url(serviceUrl);
    QNetworkRequest request(url);
    uploadFileReply = accessManager->post(request, multiPart);
    multiPart->setParent(uploadFileReply);
    QObject::connect(uploadFileReply, SIGNAL(finished()), this, SLOT(httpUploadFinished()));
    QObject::connect(uploadFileReply, SIGNAL(downloadProgress(qint64 ,qint64)), this, SLOT(loadProgress(qint64 ,qint64)));
}

void HttpService::httpUploadFinished(){
    if(uploadFileReply->error() == QNetworkReply::NoError){
        //qDebug() << "文件上传成功";
        emit progressBar(1.0);
        file->remove();
        file->flush();
        file->close();
        uploadFileReply->deleteLater();
        uploadFileReply=nullptr;
        delete file;
        file=nullptr;
    }else{
        //qDebug() << "文件上传失败";
        uploadFileReply->deleteLater();
    }
}

void HttpService::loadProgress(qint64 bytesSent, qint64 bytesTotal){
//    float percent=static_cast<float>(bytesSent * 1.0 / bytesTotal);
    //qDebug() << "percent:" << percent;
}
