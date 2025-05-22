#include <iostream>

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

protected:

private:
    Singleton() = default;
    Singleton(const Singleton& obj) = default;
    Singleton& operator=(const Singleton& obj) = default;

    static Singleton* m_obj;        // 单例对象
};
// 初始化静态成员变量
Singleton* Singleton::m_obj = new Singleton;

#endif

// 懒汉模式 -- 什么时候使用这个单例对象, 在使用的时候再去创建对应的实例
// 节省内存空间
#if 1
class Singleton
{
public:
    static Singleton* getInstance(){
        if(m_obj == nullptr){
            m_obj = new Singleton();
        }
        return m_obj;
    }

    void printf(){
        cout << "hello world" << endl;
    }

protected:

private:
    Singleton() = default;
    Singleton(const Singleton& obj) = default;
    Singleton& operator=(const Singleton& obj) = default;

    static Singleton* m_obj;        // 单例对象
};
// 初始化静态成员变量
Singleton* Singleton::m_obj = nullptr;
#endif


// 定义一个单例模式的任务队列
int main()
{
    // 创建对象
    Singleton* obj1 = Singleton::getInstance();
    obj1->printf();

    return 0;
}