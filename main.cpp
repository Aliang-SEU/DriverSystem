#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QtQml>
#include <QThread>

#include <src/CameraImageProvider.h>
#include <src/CameraCaptureThread.h>
#include <src/Processor.h>
#include <DriverDatabase.h>
#include <FatigueAlarm.h>
#include <memory>

int main(int argc, char *argv[]){

    ::google::InitGoogleLogging(argv[0]);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QPM_INIT(engine)
    //注册cv::Mat类型
    qRegisterMetaType<cv::Mat>("cv::Mat");

    std::shared_ptr<QThread> cameraThread = std::make_shared<QThread>(&app); //摄像头读取线程
    std::shared_ptr<QThread> imageProviderThread = std::make_shared<QThread>(&app); //图像获取线程
    std::shared_ptr<QThread> imageProcessingThread = std::make_shared<QThread>(&app); //图像处理线程

    std::shared_ptr<CameraCaptureThread> cameraCapture = std::make_shared<CameraCaptureThread>(); //视频获取对象
    std::shared_ptr<CameraImageProvider> imageProvider = std::make_shared<CameraImageProvider>(); //图像显示对象
    std::shared_ptr<Processor> processor = std::make_shared<Processor>(); //图像处理对象

    std::shared_ptr<DriverDatabase> database = std::make_shared<DriverDatabase>();  //数据库对象
    database->initSqlTableModel();
    std::shared_ptr<QSqlTableModel> model = database->getModel();    //数据模型对象

    std::shared_ptr<FatigueAlarm> fatigueAlarm = std::make_shared<FatigueAlarm>();  //报警模块

    cameraCapture->moveToThread(cameraThread.get());
    imageProvider->moveToThread(imageProviderThread.get());
    processor->moveToThread(imageProcessingThread.get());

    cameraThread->start();
    imageProviderThread->start();
    imageProcessingThread->start();

    QObject::connect(cameraCapture.get(), SIGNAL(imageReady(cv::Mat)),
                     processor.get(), SLOT(processNextFrame(cv::Mat)));

    QObject::connect(processor.get(), SIGNAL(frame(cv::Mat)),
                     imageProvider.get(), SLOT(setMatToImage(cv::Mat)));

    QObject::connect(processor.get(), SIGNAL(eyeFatigue()),
                     fatigueAlarm.get(), SIGNAL(fatigueAlarm()));

    QObject::connect(processor.get(), SIGNAL(mouthFatigue()),
                     fatigueAlarm.get(), SIGNAL(fatigueAlarm()));

    QObject::connect(processor->videoRecord.get(), SIGNAL(progressBar(float)),
                     fatigueAlarm.get(), SLOT(progressBar(float)));

    engine.rootContext()->setContextProperty("cameraCapture", cameraCapture.get());
    engine.rootContext()->setContextProperty("myModel", model.get());
    engine.rootContext()->setContextProperty("processor", processor.get());
    engine.rootContext()->setContextProperty("fatigueAlarm", fatigueAlarm.get());
    engine.addImageProvider("video", imageProvider.get());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

