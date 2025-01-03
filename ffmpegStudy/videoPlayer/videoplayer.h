#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <QThread>

extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/pixfmt.h>
#include <libavdevice/avdevice.h>
#include <libavutil/imgutils.h>
#include <libswresample/swresample.h>
}
#include <QImage>

#define FILE_PATH "/home/yuanjl/ffmpegStudy/car.mp4"

class VideoPlayer : public QThread
{
    Q_OBJECT    //宏，使程序可以使用信号与槽机制；
public:
    VideoPlayer();
    ~VideoPlayer();

protected:
    void run();

private:
    int init();

    AVFormatContext *pFormatCtx;    //  上下文
    AVStream *stream;               // 流
    AVCodecContext *pCodecCtx;      // 解码器上下文
    AVCodec *pCodec;                // 解码器
    AVFrame *pFrame;                // YUV420帧
    AVFrame *pFrameRGB;             // RGB帧
    AVPacket *packet;               // 封装包
    uint8_t *out_buffer;
    int videoStream;
    QString rtspUrl = "rtsp://rtspstream:c55e63cf6d099c8a00cc7e12daed7a05@zephyr.rtsp.stream/movie";

signals:
     void  sig_GetOneFrame(QImage);  //没获取到一帧图像 就发送此信号

};

#endif // VIDEOPLAYER_H
