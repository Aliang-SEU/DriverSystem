#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <opencv2/opencv.hpp>

/** 该类用于qml界面的显示,详细用法见帮助文档中　QQuickImageProvider Class
 * @brief The CameraImageProvider class
 */
class CameraImageProvider : public QObject, public QQuickImageProvider{
  Q_OBJECT

public:
  explicit CameraImageProvider(QObject *parent = nullptr);
  QImage requestImage(const QString &id, QSize *size,
                      const QSize &requestedSize);
public slots:
  void setImage(const QImage &image);
  void setMatToImage(const cv::Mat &image);


private:
  QImage convertCvMatToQImage(const cv::Mat &matrix);
  QImage image;
};

#endif // IMAGEPROVIDER_H
