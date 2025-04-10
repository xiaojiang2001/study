#ifndef _MACRO_H_
#define _MACRO_H_

#define DEVICE_IP "192.168.10.129"                          // 设备 IP
#define DEVICE_PORT 8080                                    // 设备服务端口
#define USERNAME "admin"                                    // 登录用户名
#define PASSWORD "admin123"                                 // 登录密码
#define VIDEO_WIDTH 1920                                    // 视频宽度
#define VIDEO_HEIGHT 1080                                   // 视频高度
#define FRAME_RATE 30                                       // 视频帧率
#define RTSP_URL "rtsp://192.168.10.129:8554/output.mkv"    // RTMP流地址

// 定义一个宏来返回不支持的功能错误
#define RETURN_NOT_SUPPORTED_ERROR(soap)                                                    \
    do                                                                                      \
    {                                                                                       \
        char faultstring[256];                                                              \
        printf("line %d\n", __LINE__);                                                      \
        snprintf(faultstring, sizeof(faultstring),                                          \
                 "The requested function '%s' is not supported by the server.", __func__);  \
        const char *faultdetail = "This service does not support the requested operation."; \
        return soap_receiver_fault(soap, faultstring, faultdetail);                         \
    } while (0)

#endif // _MACRO_H_
