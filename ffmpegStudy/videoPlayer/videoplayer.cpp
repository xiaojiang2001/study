#include "videoplayer.h"
#include <QDebug>
#include <QTimer>
#include <QImage>

static struct SwsContext *img_convert_ctx = nullptr;    // 转换格式上下文

VideoPlayer::VideoPlayer()
{
    videoStream = -1;
    qDebug() << "in VideoPlayer";
    int ret = init();
    if(ret != 0) {
        qDebug() << "init failed";
        return;
    }
    start();
}

VideoPlayer::~VideoPlayer()
{

}

void VideoPlayer::run()
{
    qDebug() << " in run";
    while(1)
    {
        // 读取一帧视频
        if (av_read_frame(pFormatCtx, packet) < 0) {
            qDebug() << "packet read ending.\n";
            break;    // 读完了
        }
        // 7.解码
        int got_picture;
        if (packet->stream_index == videoStream)
        {
            int ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture,packet);
            if (ret < 0) {
                printf ("decode error.\n");
            }
            // 8.转换格式 YUV420P 转 RGB24
            if (got_picture) {
                sws_scale(img_convert_ctx, (uint8_t const * const *) pFrame->data,
                            pFrame->linesize, 0, pCodecCtx->height, pFrameRGB->data, pFrameRGB->linesize);
                //把这个RGB数据 用QImage加载
                QImage tmpImg((uchar *)out_buffer,pCodecCtx->width,pCodecCtx->height,QImage::Format_RGB32);
                QImage image = tmpImg.copy();  //把图像复制一份 传递给界面显示
                emit sig_GetOneFrame(image);   //发送信号
            }
        }
        av_free_packet(packet);
    }
}

int VideoPlayer::init()
{

    // 1. 初始化FFMPEG
    av_register_all();

    // 2. 分配一个AVFormatContext
    pFormatCtx = avformat_alloc_context();

    // 3. 打开视频文件
    //  rtspUrl.toUtf8().constData()
    if(avformat_open_input(&pFormatCtx, FILE_PATH, NULL, NULL) != 0){
        qDebug() << "can't open the file.\n";
        return -1;
    }
    printf ("Open Video Success ..............\n");
    // 检索信流信息
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        qDebug() << "Could't find stream infomation.\n";
        return  -1;
    }
    

    //  4. 查找文件视频流
    //循环查找视频中包含的流信息，直到找到视频类型的流
    //便将其记录下来 保存到videoStream变量中
    //这里我们现在只处理视频流  音频流先不管他
    for (int i = 0; i < pFormatCtx->nb_streams; i++)
    {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
            break;
        }
    }
    // 如果videoStream为-1 说明没有找到视频流
    if (videoStream == -1) {
        qDebug() << "Didn't find a video stream.\n";
        return -1;
    }
    qDebug() << "Find The Video Stream Information Success ..............\n";

    // 5. 解码器解码
    stream = pFormatCtx->streams[videoStream];          // 获取视频流
    pCodecCtx = stream->codec;                          // 获取解码器上下文
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id); // 查找解码器
    if (pCodec == NULL) {
        qDebug() << "Codec not found.\n";
        return -1;
    }
    qDebug() << "Find The Codec Information Success ..............\n";
    
    // 打开解码器
    if  (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        printf("Could not open codec.\n");
        return -1;
    }
    qDebug() << "Open Codec Success ..............\n";

    pFrame = av_frame_alloc();      // 分配一个AVFrame
    pFrameRGB = av_frame_alloc();   // 分配一个AVFrame
    
    // 转换格式
    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height,
            pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height,
            AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);

    // 确定保存图片的格式
    int numBytes = avpicture_get_size(AV_PIX_FMT_RGB32, pCodecCtx->width,pCodecCtx->height);
    // 分配保存图片的内存
    out_buffer = (uint8_t *) av_malloc(numBytes *  sizeof (uint8_t));
    // 填充保存图片的内存
    avpicture_fill((AVPicture *) pFrameRGB, out_buffer, AV_PIX_FMT_RGB32,   pCodecCtx->width, pCodecCtx->height);

    // 6.读取视频
    int  y_size = pCodecCtx->width * pCodecCtx->height;
    packet = (AVPacket *)  malloc ( sizeof (AVPacket));  //分配一个packet
    av_new_packet(packet, y_size);                      //分配packet的数据
    // av_dump_format(pFormatCtx, 0, file_path, 0);        //输出视频信息
    printf ("Start Decoding Video ..............\n");

    return 0;
}
