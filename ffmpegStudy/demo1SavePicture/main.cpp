#include <iostream>

using namespace std;

extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/pixfmt.h>
#include <libavdevice/avdevice.h>
#include <libavutil/imgutils.h>
#include <libswresample/swresample.h>
}

// 现在我们需要做的是让SaveFrame函数能把RGB信息定稿到一个PPM格式的文件中。
// 我们将生成一个简单的PPM格式文件，请相信，它是可以工作的。
void SaveFrameToPPM(AVFrame *pFrame, int width, int height, int index)
{
   FILE *pFile;
   char szFilename[32];
   int y;
 
   // Open file
   sprintf(szFilename, "frame%d.ppm", index);
   pFile = fopen(szFilename, "wb");
   if (pFile==NULL)
        return ;
 
   // Write header
   fprintf(pFile, "P6 %d %d 255", width, height);
 
    // Write pixel data
    for(y = 0; y < height; y++) {
        fwrite (pFrame->data[0] + y * pFrame->linesize[0], 1, width * 3, pFile);
    }
 
   fclose (pFile);
}
int main()
{
    cout << "Hello World!" << endl;
    cout << "hello world";
    cout << "sersion: " << av_version_info();
    cout <<  avcodec_version();

    char *file_path = "/home/yuanjl/ffmpegStudy/car.mp4";
    AVFormatContext *pFormatCtx;    //  上下文
    AVStream *stream;               // 流
    AVCodecContext *pCodecCtx;      // 解码器上下文
    AVCodec *pCodec;                // 解码器
    AVFrame *pFrame;                // YUV420帧
    AVFrame *pFrameRGB;             // RGB帧
    AVPacket *packet;               // 封装包
    
    static  struct  SwsContext *img_convert_ctx;    // 转换格式上下文

    // 1. 初始化FFMPEG
    av_register_all();

    // 2. 分配一个AVFormatContext
    pFormatCtx = avformat_alloc_context();

    // 3. 打开视频文件
    if(avformat_open_input(&pFormatCtx, file_path, NULL, NULL) != 0){
        printf("can't open the file.\n");
        return -1;
    }
    printf ("Open Video Success ..............\n");
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        printf ("Could't find stream infomation.\n");
        return  -1;
    }
    printf ("Find Stream Information Success ..............\n");

    //  4. 查找文件视频流
    //循环查找视频中包含的流信息，直到找到视频类型的流
    //便将其记录下来 保存到videoStream变量中
    //这里我们现在只处理视频流  音频流先不管他
    int videoStream = -1;
    for (int i = 0; i < pFormatCtx->nb_streams; i++)
    {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
        }
    }
    // 如果videoStream为-1 说明没有找到视频流
    if (videoStream == -1) {
        printf ("Didn't find a video stream.\n");
        return -1;
    }
    printf ("Find The Video Stream Information Success ..............\n");

    // 5. 解码器解码
    stream = pFormatCtx->streams[videoStream];          // 获取视频流
    pCodecCtx = stream->codec;                          // 获取解码器上下文
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id); // 查找解码器
    if (pCodec == NULL) {
        printf ("Codec not found.\n");
        return -1;
    }
    printf ("Find The Codec Information Success ..............\n");
    // 打开解码器
    if  (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        printf("Could not open codec.\n");
        return -1;
    }
    printf ("Open Codec Success ..............\n");

    pFrame = av_frame_alloc();      // 分配一个AVFrame
    pFrameRGB = av_frame_alloc();   // 分配一个AVFrame
    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height,
            pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height,
            AV_PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);
    // 确定保存图片的格式
    int numBytes = avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width,pCodecCtx->height);
    // 分配保存图片的内存
    uint8_t *out_buffer = (uint8_t *) av_malloc(numBytes *  sizeof (uint8_t));
    // 填充保存图片的内存
    avpicture_fill((AVPicture *) pFrameRGB, out_buffer, AV_PIX_FMT_RGB24,   pCodecCtx->width, pCodecCtx->height);

    // 6.读取视频
    int  y_size = pCodecCtx->width * pCodecCtx->height;
    packet = (AVPacket *)  malloc ( sizeof (AVPacket));  //分配一个packet
    av_new_packet(packet, y_size);                      //分配packet的数据
    // av_dump_format(pFormatCtx, 0, file_path, 0);        //输出视频信息
    int idx = 0;
    printf ("Start Decoding Video ..............\n");
    while (1)
    {
        // 读取一帧视频
        if (av_read_frame(pFormatCtx, packet) < 0) {
            printf ("packet read ending.\n");
            break;    // 读完了
        }
        // 7.解码
        int got_picture;
        if (packet->stream_index == videoStream)
        {
            int ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture,packet);
            if  (ret < 0) {
                printf ("decode error.\n");
                return -1;
            }
            // 8.转换格式 YUV420P 转 RGB24
            if (got_picture) {
                sws_scale(img_convert_ctx, (uint8_t const * const *) pFrame->data, 
                            pFrame->linesize, 0, pCodecCtx->height, pFrameRGB->data, pFrameRGB->linesize);
                // // 9. 保存图片 保存50张图片
                SaveFrameToPPM(pFrameRGB, pCodecCtx->width,pCodecCtx->height,idx++);
                if (idx > 10)  {
                    printf ("Save Picture Ending.\n");
                    break;  //保存10张图片
                }   
            }
        }
        av_free_packet(packet);
    }
    printf("**************Done.\n");
    av_free(out_buffer);
    av_free(pFrameRGB);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);

    return 0;
}
