#ifndef FILEUPLOAD_H
#define FILEUPLOAD_H


#include<QObject>
#include<QNetworkReply>
#include<QNetworkAccessManager>
#include<QEventLoop>
#include<QNetworkReply>
#include<QFile>
#include<QHttpMultiPart>
#include<memory>

class HttpService : public QObject{
    Q_OBJECT
public:
    HttpService();
public slots:
    void uploadVideoFile(QString filepath, QString folder);
private:
    std::shared_ptr<QEventLoop> loop;
    QNetworkReply *uploadFileReply;
    std::shared_ptr<QNetworkAccessManager> accessManager;
    const QString serverIP="http://10.193.4.9:8080/";  //10.193.4.55//实验室服务器的ＩＰ地址
    const QString uploadService="/upload";
    QFile *file;

public slots:
    void httpUploadFinished();
    void loadProgress(qint64, qint64);

signals:
    void progressBar(float);
};

#endif // FILEUPLOAD_H
