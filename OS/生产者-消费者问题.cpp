#include <iostream>  
#include <bits/stdc++.h>
#include <semaphore.h>  
#include <thread>  
#define N 100

using namespace std;

void P(sem_t sem) { }
void V(sem_t sem) { }

// 1. ⽣产者在⽣成数据后，放在⼀个缓冲区中；
// 2. 消费者从缓冲区取出数据处理；
// 3. 任何时刻，只能有⼀个⽣产者或消费者可以访问缓冲区

// 任何时刻只能有⼀个线程操作缓冲区，说明操作缓冲区是临界代码，需要互斥；
// 缓冲区空时，消费者必须等待⽣产者⽣成数据；缓冲区满时，⽣产者必须等待消费者取出数据。说明⽣产者和消费者需要同步

sem_t Mutex = 1;            // 临界访问
sem_t fullBuffer  = N;      // 表示缓冲区【满槽】的个数
sem_t emptyBuffer = 0;      // 表示缓冲区【空槽】的个数


void produce()
{
    while (true)
    {
        P(emptyBuffer);     // 生产者 空槽-1
        P(Mutex);
        //生产数据
        V(Mutex);
        V(fullBuffer);
    }
}

void consumer()
{
    while (true)
    {
        P(fullBuffer);      // 满槽-1
        P(Mutex);
        // 消费数据
        V(Mutex);
        V(emptyBuffer);     // 空槽+1
    }
}