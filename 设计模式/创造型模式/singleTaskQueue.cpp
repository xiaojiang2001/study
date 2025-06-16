#include <iostream>
#include <queue>
#include <mutex>
#include <thread>

using namespace std;

// 饿汉模式
class TaskQueue
{
public:
    TaskQueue(const TaskQueue& queue) = delete;             // 删除拷贝构造函数
    TaskQueue& operator=(const TaskQueue& queue) = delete;  // 删除拷贝赋值操作符重载函数

    // 公有的获取实例对象
    static TaskQueue* getInstance() {
        return taskQueue;
    }

    // 添加任务
    void addTask(int task){
        lock_guard<mutex> lock(m_mutex);
        m_que.push(task);
    }

    // 删除任务
    bool popTask() {
        lock_guard<mutex> lock(m_mutex);
        if(m_que.empty())
            return false;
        m_que.pop();
        return true;
    }

    // 获取任务
    int getTask() {
        lock_guard<mutex> locker(m_mutex);
        if(m_que.empty())
            return -1;
        int task = m_que.front();
        return task;
    }

    // 判断任务队列是否为空
    bool isEmpty() {
        lock_guard<mutex> lock(m_mutex);
        bool flag = m_que.empty();
        return flag;
    }


private:
    TaskQueue() = default;          // 构造函数私有化
    static TaskQueue* taskQueue;    // 单例对象
    // 定义任务队列
    queue<int> m_que;
    mutex m_mutex;
};
// 类外部初始化类的静态成员变量
TaskQueue* TaskQueue::taskQueue = new TaskQueue();


void func1(TaskQueue* taskQueue)
{
    // 生产者
    for (int i = 0; i < 20; i++) {
        taskQueue->addTask(i + 100);
        cout << "+++ push data: " << i + 100 << ", threadID: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(100));       // 休眠一定的时间长度
    }

}

void func2(TaskQueue* taskQueue)
{
    // 消费者
    this_thread::sleep_for(chrono::milliseconds(500));   
    while (!taskQueue->isEmpty())
    {
        int task = taskQueue->getTask();
        taskQueue->popTask();
        cout << "--- get data: " << task << ", threadID: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(500));  
    }
}

int main()
{
    TaskQueue* taskQueue = TaskQueue::getInstance();

    thread thread1(func1, taskQueue);   // 生产者线程
    thread thread2(func2, taskQueue);   // 消费者线程

    
    thread1.join();
    thread2.join();

    return 0;
}