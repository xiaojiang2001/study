#include <iostream>
#include <mutex>
#include <atomic>

using namespace std;

// 饿汉模式 -- 定义类的时候创建单例对象
#if 0
class Singleton
{
public:
    static Singleton* getInstance(){
        return m_obj;
    }
    void printf(){
        cout << "hello world" << endl;
    }

    // 拷贝赋值操作符重载函数函数，也可以使用私有化
    Singleton& operator=(const Singleton& obj) = delete;
protected:

private:
    // 构造函数私有化
    Singleton() = default; 
    // 拷贝构造函数私有化
    Singleton(const Singleton& obj) = default;

    static Singleton* m_obj;        // 单例对象
};
// 初始化静态成员变量
Singleton* Singleton::m_obj = new Singleton();
#endif

// 懒汉模式 -- 什么时候使用这个单例对象, 在使用的时候再去创建对应的实例
// 节省内存空间
#if 1

class Singleton
{
public:
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& obj) = delete;
    // 使用互斥锁
    // static Singleton* getInstance()
    // {
    //     if(m_obj == nullptr)
    //     {
    //         m_mutex.lock();             // 加锁
    //         if(m_obj == nullptr){
    //             m_obj = new Singleton();
    //         }
    //         m_mutex.unlock();
    //     }
    //     return m_obj;
    // }

    // 使用原子变量
    static Singleton* getInstance()
    {
        Singleton* obj = m_obj.load();   // 读取原子变量的值  
        if(obj == nullptr)
        {
            m_mutex.lock();             // 加锁
            obj = m_obj.load();         // 读取原子变量的值
            if(obj == nullptr){
                obj = new Singleton();
                m_obj.store(obj);       // 保存到原子变量
            }
            m_mutex.unlock();
        }
        return obj;
    }



    void printf(){
        cout << "hello world" << endl;
    }

protected:

private:
     Singleton() = default;
    // static Singleton* m_obj;         // 单例对象
    static atomic<Singleton*>   m_obj;  // 单例对象,原子变量管理
    static mutex m_mutex;
};
// 初始化静态成员变量
atomic<Singleton*> Singleton::m_obj;
mutex Singleton::m_mutex;
#endif


// 定义一个单例模式的任务队列
int main()
{
    // 创建对象
    Singleton* obj1 = Singleton::getInstance();
    obj1->printf();

    return 0;
}