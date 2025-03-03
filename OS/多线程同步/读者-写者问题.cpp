#include <iostream>  
#include <bits/stdc++.h>
#include <semaphore.h>  
#include <thread>  
using namespace std;
void P(sem_t sem) { }
void V(sem_t sem) { }


// 读者-写者的问题描述
// 「读-读」允许：同⼀时刻，允许多个读者同时读
// 「读-写」互斥：没有写者时读者才能读，没有读者时写者才能写
// 「写-写」互斥：没有其他写者时，写者才能

/************************* 方案一 **************************/
sem_t  wMutex = 1;  // 控制写操作的互斥量, 初始值为 1
int rCount = 0;     // 正在进行读操作的读者个数, 初始化为0
sem_t rCountMutex = 1;  // 控制对 Rcount 的互斥修改，初始值为 1

void write()
{
    while (true)
    {
        P(wMutex);
        write();
        V(wMutex);
    }
}

void read()
{
    while (true)
    {
        P(rCountMutex);     // 保护rCount修改
        rCount++;           // 读者数++
        if(rCount == 1)     // 是否为第一个读者，后续读者不需要拿锁，已经有锁了
            P(wMutex);
        V(rCountMutex);

        read();

        P(rCountMutex);     // 保护rCount修改
        rCount++;           // 读者数--
        if(rCount == 0)     // 最后一个读者都走了，释放锁，可以写了
            V(wMutex);
        V(rCountMutex);
    }
}
// 该策略是读者优先的策略，因为只要有读者正在读的状态，后来的读者都可以直接进⼊，如果读者持续不断进⼊，则写者会处于饥饿状态



/************************* 方案二 **************************/
// 只要有写者准备要写⼊，写者应尽快执⾏写操作，后来的读者就必须阻塞；
// 如果有写者持续不断写⼊，则读者就处于饥饿;
int wCount = 0;             // 统计写者数量
int rCount = 0;             // 统计读者数量
sem_t wCountMutex = 1;      // 保护写者数量锁，初始值为1
sem_t rCountMutex = 1;      // 保护读者数量锁，初始值为1

sem_t rMutex = 1;           // 控制读写互斥信号量，初始值为1
sem_t wDateMutex = 1;       // 控制写者写操作互斥信号量，初始化为1

void read()
{
    while (true)
    {
        P(rMutex);          // 读写互斥
        P(rCountMutex);     // 保护rCount
        rCount++;
        if(rCount == 1) // 第一个读者进入, 有写者则阻塞
            P(wDateMutex);
        V(rCountMutex);
        V(rMutex);          

        read();

        P(rCountMutex);     // 保护rCount
        rCount--;
        if(rCount == 0)
            V(wDateMutex);
        P(rCountMutex);     // 保护rCount
    } 
}

void write()
{
    // 下列5行同方案一的read
    P(wCountMutex);
    wCount++;
    if(wCount == 1)
        P(rMutex);      // 第一个写者来了, 加锁
    V(wCountMutex);

    // 写写互斥
    P(wDateMutex);
    write();
    V(wDateMutex);

    // 下列5行同方案一的read
    P(wCountMutex);
    wCount--;
    if(wCount == 0)     // 等到最后一个写者走了，释放锁
        V(rMutex);     
    V(wCountMutex);
}
// 注意，这⾥ rMutex 的作⽤，开始有多个读者读数据，它们全部进⼊读者队列，此时来了⼀个写者，执⾏
// 了 P(rMutex) 之后，后续的读者由于阻塞在 rMutex 上，都不能再进⼊读者队列，⽽写者到来，则可以
// 全部进⼊写者队列，因此保证了写者优先。
// 同时，第⼀个写者执⾏了 P(rMutex) 之后，也不能⻢上开始写，必须等到所有进⼊读者队列的读者都执⾏
// 完读操作，通过 V(wDataMutex) 唤醒写者的写操作


/************************* 方案二 **************************/
// 1. 优先级相同；
// 2. 写者、读者互斥访问；
// 3. 只能⼀个写者访问临界区；
// 4. 可以有多个读者同时访问临街资源
sem_t wmutex = 1;       // 写者互斥访问
int rCount = 0;         // 正在读者个数
sem_t rCountMutex = 1;  // 保护读者个数信号量
sem_t flag = 1;         // 用于实现公平竞争，初始化为1

// 对比方案1程序，只添加了 flag 信号量
void write()
{
    while (true)
    {
        P(flag);
        P(wMutex);
        write();
        V(wMutex);
        V(flag);
    }
}

void read()
{
    while (true)
    {
        P(flag);
        P(rCountMutex);     // 保护rCount修改
        rCount++;           // 读者数++
        if(rCount == 1)     // 是否为第一个读者，后续读者不需要拿锁，已经有锁了
            P(wMutex);
        V(rCountMutex);
        V(flag);
        
        read();

        P(rCountMutex);     // 保护rCount修改
        rCount++;           // 读者数--
        if(rCount == 0)     // 最后一个读者都走了，释放锁，可以写了
            V(wMutex);
        V(rCountMutex);
    }
}