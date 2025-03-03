#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

queue<int> dataQueue;
mutex queueMutex;           // 用于保护队列的互斥访问
condition_variable condVar; // 条件变量
bool stop = false;

/*
notify_one
    作用：唤醒一个等待条件变量的线程。
    行为：如果有多个线程在等待条件变量，notify_one 只会唤醒其中一个线程。具体唤醒哪个线程是未定义的，由操作系统决定。
    适用场景：当只需要唤醒一个线程来处理某个条件时，使用 notify_one 可以提高效率，避免不必要的唤醒。
notify_all
    作用：唤醒所有等待条件变量的线程。
    行为：所有等待条件变量的线程都会被唤醒，然后它们会竞争锁并检查条件是否满足。
    适用场景：当有多个线程都在等待同一个条件，并且所有这些线程都需要被唤醒来处理这个条件时，使用 notify_all 是合适的。
*/

void producer() {
    for (int i = 0; i < 10; ++i) 
    {

        this_thread::sleep_for(chrono::milliseconds(200)); // 模拟生产时间 200ms
        {
            lock_guard<mutex> lock(queueMutex);
            dataQueue.push(i);
            cout << "Produced: " << i << endl;
        }
        condVar.notify_one();   // 通知消费者
    }
    {
        lock_guard<mutex> lock(queueMutex);
        stop = true;
    }
    condVar.notify_all();   // 通知消费者停止
}

void consumer() 
{
    while (true) 
    {
        unique_lock<mutex> lock(queueMutex);

        // 等待数据或停止信号
        condVar.wait(lock, []{ 
            return !dataQueue.empty() || stop == true; 
        }); 

        if (dataQueue.empty()) {
            break;
        }
        int data = dataQueue.front();
        dataQueue.pop();
        lock.unlock();
        cout << "Consumed: " << data << endl;

        if(stop)
            break;
    }
}

int main() {
    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}