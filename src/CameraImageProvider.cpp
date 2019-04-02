#include "CameraImageProvider.h"
#include <QDebug>

CameraImageProvider::CameraImageProvider(QObject *parent)
    : QObject(parent),
      QQuickImageProvider(QQuickImageProvider::Image) {
  image = QImage(1, 1, QImage::Format_RGB888);
  image.fill(0);
}

QImage CameraImageProvider::requestImage(const QString &id, QSize *size,
                                         const QSize &requestedSize) {
  Q_UNUSED(id)
  *size = image.size();
  if (requestedSize.width() > 0 && requestedSize.height() > 0) {
    return image.scaled(requestedSize);
  } else {
    return image;
  }
}


QImage CameraImageProvider::convertCvMatToQImage(const cv::Mat &matrix) {
  cv::Mat rgbMatrix;
  cv::cvtColor(matrix, rgbMatrix, CV_BGR2RGB);
  return QImage(rgbMatrix.data, rgbMatrix.cols, rgbMatrix.rows,
                QImage::Format_RGB888);
}

void CameraImageProvider::setMatToImage(const cv::Mat &image) {
  this->image = convertCvMatToQImage(image);
}

void CameraImageProvider::setImage(const QImage &image) {
  this->image = image;
}
