#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#define MESSAGE_QUEUE "/mq"

#if 0

mqd_t mq_open(const char *name,int oflag, mode_t mode,struct mq_attr *attr)             // 创建消息队列 
int mq_send(mqd_t mqdes,const char *msg_ptr,size_t msg_len,unsigned int msg_prio);      // 发送消息
ssize_t mq_receive(mqd_t mqdes, char *mdg_ptr,size_t msg_len,unsigned int *msg_prio);   // 接收消息
int mq_close(mqd_t mqdes);          // 关闭消息队列       
int mq_unlink(const char *name);    // 删除消息队列

struct mq_attr {
    long mq_flags;      // 队列标志
    long mq_maxmsg;     // 最大消息数
    long mq_msgsize;    // 最大消息长度
    long mq_curmsgs;    // 当前消息数
    long mq_padding[4]; // 保留字段
};

union sigval 
{       
    /* Data passed with notification */
     int   sival_int;       /* Integer value */
     void  *sival_ptr;      /* Pointer value */
};

 struct sigevent 
{
     int   sigev_notify;        /* Notification method */
     int   sigev_signo;         /* Notification signal */
     union sigval sigev_value;  /* Data passed with notification */
     void (*sigev_notify_function) (union sigval);  /* Function used for thread notification (SIGEV_THREAD) */
     void  *sigev_notify_attributes;    /* Attributes for notification thread   (SIGEV_THREAD) */
     pid_t  sigev_notify_thread_id;     /* ID of thread to signal (SIGEV_THREAD_ID); Linux-specific */
};


#endif

void* sender_thread(void* arg)
{
    mqd_t mqd_fd = *(mqd_t*)arg;
    int i = 20;
    while(i > 0) {
        char buf[1024] = {0};
        int len = sprintf(buf, "hello world %d", rand() % 100);
        if(mq_send(mqd_fd, buf, len, 0) != 0) {
            perror("mq_send");
            exit(1);
        }
        printf("send: %s\n", buf);
        sleep(1);
        i--;
    }
    return NULL;
}

// void* receiver_thread(void* arg)
// {
//     mqd_t mqd_fd = *(mqd_t*)arg;
//     int i = 10;
//     while(i >  0) {
//         char buf[1024] = {0};
//         int len = mq_receive(mqd_fd, buf, sizeof(buf), NULL);
//         if(len == -1) {
//             perror("mq_receive");
//             exit(1);
//         }
//         printf("receive: %s\n", buf);
//         i--;
//     }
// }

void notify_thread(union sigval arg)
{
    mqd_t mqd_fd = -1;
    mqd_fd = *(mqd_t *)arg.sival_ptr;
    char buf[1024] = {0};
    ssize_t ret = mq_receive(mqd_fd, buf, sizeof(buf), NULL);
    if(ret == -1) {
        perror("mq_receive");
        exit(1);
    }

    printf("receive: %s\n", buf);
    struct sigevent sev;
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_attributes = NULL;
    sev.sigev_value.sival_ptr = &mqd_fd;
    sev.sigev_notify_function = notify_thread;
    if(mq_notify(mqd_fd, &sev) != 0) {
        perror("mq_notify");
        exit(1);
    }

}


int main()
{
    pthread_t sender, receiver;

    mqd_t mqd_fd = mq_open(MESSAGE_QUEUE, O_RDWR | O_CREAT, 0666, NULL);
    if(mqd_fd == -1) {
        perror("mq_open");
        exit(1);
    }

    struct mq_attr attr;                // 设置消息队列属性
    attr.mq_flags = 0;                  // 阻塞
    attr.mq_maxmsg = 10;                // 最大消息数
    attr.mq_msgsize = 1024;             // 最大消息长度
    attr.mq_curmsgs = 0;                //  当前消息数
    mq_setattr(mqd_fd, &attr, NULL);    // 设置消息队列属性


    struct sigevent sev;
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_attributes = NULL;
    sev.sigev_value.sival_ptr = &mqd_fd;
    sev.sigev_notify_function = notify_thread;
    if(mq_notify(mqd_fd, &sev) != 0) {
        perror("mq_notify");
        exit(1);
    }


    if(pthread_create(&sender, NULL, sender_thread, (void*)&mqd_fd) != 0) {
        perror("pthread_create");
        exit(1);
    }

    pthread_join(sender, NULL);

    sleep(5);
    mq_close(mqd_fd);
    mq_unlink(MESSAGE_QUEUE);

    return 0;
}