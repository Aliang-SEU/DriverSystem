QT += qml quick sql core multimedia
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
TEMPLATE = app

QMAKE_CXX = g++
QMAKE_CXXFLAGS += -std=c++11 -fopenmp
QMAKE_CXXFLAGS += -Wno-unused-parameter -Wno-unused-variable
QMAKE_RESOURCE_FLAGS += -compress 9 -threshold 0

#跨平台条件编译
#DEFINES += _qt_msvc_2015
if(contains(DEFINES,_qt_msvc_2015)) {
    INCLUDEPATH +=  D:/opencv/opencv-3.4.4/build\install/include \
                    D:/opencv/opencv-3.4.4/build\install/include/opencv \
                    D:/opencv/opencv-3.4.4/build\install/include/opencv2 \
                    $$quote(C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v8.0/include) \
                    D:/caffe-windows/scripts/build/include \
                    D:/caffe-windows/include \
                    C:/Users/hzl/.caffe/dependencies/libraries_v140_x64_py35_1.1.0/libraries/include \
                    C:/Users/hzl/.caffe/dependencies/libraries_v140_x64_py35_1.1.0/libraries/include/boost-1_61 \
                    src \
                    D:/tensorflow-1.4.0

}else{
    INCLUDEPATH +=  /home/nvidia/Desktop/caffe/build/install/include
    INCLUDEPATH +=  /home/hzl/Documents/caffe-master/include \
                /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \
                /usr/local/cuda/include \
                /usr/include/boost/ \
                src
}

if(contains(DEFINES,_qt_msvc_2015)){
    LIBS += D:/opencv/opencv-3.4.4/build/install/x64/vc14/lib/opencv_world344.lib \
            D:/caffe-windows/scripts/build/lib/Release/caffe.lib \
            D:/caffe-windows/scripts/build/lib/Release/caffeproto.lib \
            C:/Users/hzl/.caffe/dependencies/libraries_v140_x64_py35_1.1.0/libraries/lib/libopenblas.dll.a \
            -LC:/Users/hzl/.caffe/dependencies/libraries_v140_x64_py35_1.1.0/libraries/lib/ \
            -lboost_filesystem-vc140-mt-1_61 \
            -lboost_system-vc140-mt-1_61 \
            -lboost_thread-vc140-mt-1_61 \
            -llibboost_date_time-vc140-mt-1_61 \
            -lglog \
            -lgflags \
            -lcaffehdf5 \
            -lcaffehdf5_cpp \
            -lcaffehdf5_hl \
            -llibprotobuf \
            -llmdb \
            -lboost_python-vc140-mt-1_61 \
            D:/Python/Python35/libs/python35.lib \
            D:/tensorflow-1.4.0/tensorflow/contrib/cmake/build/Release/tensorflow.lib

}else {
    LIBS +=  -L/home/nvidia/Desktop/caffe/build/install/lib
    LIBS +=  -L/home/hzl/Documents/caffe-master/build/lib \
            -L/usr/local/lib/ \
            -lopencv_highgui \
            -lopencv_core \
            -lopencv_imgcodecs \
            -lopencv_imgproc \
            -lopencv_dnn \
            -lopencv_videoio \
            -lopencv_objdetect \
            -lopencv_calib3d \
            -lopencv_video \
            -lopencv_tracking \
            -lcaffe \
            -lopenblas \
            -lglog \
            -lprotobuf \
            -lboost_system \
            -lboost_filesystem \
            -lgomp
}


HEADERS += src/MtcnnDetector.h \
    src/CaffeLayerHeadear.h \
    src/EyeRecognition.h \
    src/Landmark.h \
    src/MouthRecognition.h \
    #src/CTaskQueue.h \
    #src/Message.h \
    src/VideoCaptureSource.h \
    #src/ConcurrentQueue.h \
    src/CaptureSequence.h \
    #src/TimeUtils.h \
    #src/MtcnnOpencv.h \
    src/PoseEstimator.h \
    src/KalmanStabilizer.h \
    src/Processor.h \
    src/DriverDatabase.h \
    src/CameraCaptureThread.h \
    src/CameraImageProvider.h \
    src/MyDBModel.h \
    src/FatigueAlarm.h \
    src/CommonVideoRecord.h \
    src/LandmarVanilla.h \
    src/LandmarkWithPose.h


SOURCES += src/MtcnnDetector.cpp \
    src/EyeRecognition.cpp \
    src/Landmark.cpp \
    src/MouthRecognition.cpp \
    src/CaptureSequence.cpp \
    #src/TimeUtils.cpp \
    #src/MtcnnOpencv.cpp \
    src/PoseEstimator.cpp \
    src/KalmanStabilizer.cpp \
    src/Processor.cpp \
    src/VideoCapturesource.cpp \
    main.cpp \
    src/DriverDatabase.cpp \
    src/CameraCaptureThread.cpp \
    src/CameraImageProvider.cpp \
    src/MyDBModel.cpp \
    src/FatigueAlarm.cpp \
    src/CommonVideoRecord.cpp \
    src/LandmarVanilla.cpp \
    src/LandmarkWithPose.cpp

RESOURCES += main.qrc material/icons/icons.qrc

DEFINES += QPM_INIT\\(E\\)=\"E.addImportPath(QStringLiteral(\\\"qrc:/\\\"));\"

include(material/material.pri)

DISTFILES += \
    qml/MainDialogDemo.qml \
    qml/DataBaseDialogDemo.qml \
    qml/SettingsDialogDemo.qml \
    UI/Label.qml \
    UI/Tooltip.qml
