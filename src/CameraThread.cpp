#include "CameraThread.h"

//*****************************************************************************
// CameraTask implementation
//*****************************************************************************

CameraTask::CameraTask(BetterVideoCapture* camera, QVideoFrame* videoFrame, unsigned char* cvImageBuf, int width, int height)
{
    this->running = true;
    this->camera = camera;
    this->videoFrame = videoFrame;
    this->cvImageBuf = cvImageBuf;
    this->width = width;
    this->height = height;
}

CameraTask::~CameraTask()
{
    //Leave camera and videoFrame alone, they will be destroyed elsewhere
}

void CameraTask::stop()
{
    running = false;
}

void CameraTask::convertUVsp2UVp(unsigned char* __restrict srcptr, unsigned char* __restrict dstptr, int stride)
{
    for(int i=0;i<stride;i++){
        dstptr[i]           = srcptr[i*2];
        dstptr[i + stride]  = srcptr[i*2 + 1];
    }
}

void CameraTask::RGB242Yuv420p( unsigned char* __restrict  destination, unsigned char* __restrict  rgb,
                                const int &width, const int &height ) {
    const size_t image_size = width * height;
    unsigned char *dst_y = destination;
    unsigned char *dst_uv = destination + image_size;



    // Y plane
    for( size_t i = 0; i < image_size; ++i ) {
        *dst_y++ = ( ( 66*rgb[3*i] + 129*rgb[3*i+1] + 25*rgb[3*i+2] ) >> 8 ) + 16;
    }
    // UV plane
    for( size_t y=0; y<height; y+=2 ) {
        for( size_t x=0; x<width; x+=2 ) {
          const size_t i = y*width + x;
          *dst_uv++ = ( ( -38*rgb[3*i] + -74*rgb[3*i+1] + 112*rgb[3*i+2] ) >> 8 ) + 128;
          *dst_uv++ = ( ( 112*rgb[3*i] + -94*rgb[3*i+1] + -18*rgb[3*i+2] ) >> 8 ) + 128;
      }
    }
}
void CameraTask::doWork()
{

    if(videoFrame)
        videoFrame->map(QAbstractVideoBuffer::ReadOnly);

    while(running && videoFrame != NULL && camera != NULL){
        if(!camera->grabFrame())
            continue;
        unsigned char* cameraFrame = camera->retrieveFrame();

        //Get camera image into screen frame buffer
        if(videoFrame){

        }

        //Export camera image
        if(cvImageBuf){

        }

        emit imageReady();
    }
}

//*****************************************************************************
// CameraThread implementation
//*****************************************************************************

CameraThread::CameraThread(BetterVideoCapture* camera, QVideoFrame* videoFrame, unsigned char* cvImageBuf, int width, int height)
{
    task = new CameraTask(camera,videoFrame,cvImageBuf,width,height);
    task->moveToThread(&workerThread);
    connect(&workerThread, SIGNAL(started()), task, SLOT(doWork()));
    connect(task, SIGNAL(imageReady()), this, SIGNAL(imageReady()));
}

CameraThread::~CameraThread()
{
    stop();
    delete task;
}

void CameraThread::start()
{
    workerThread.start();
}

void CameraThread::stop()
{
    if(task != NULL)
        task->stop();
    workerThread.quit();
    workerThread.wait();
}

