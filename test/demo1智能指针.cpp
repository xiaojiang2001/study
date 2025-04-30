#include <iostream>

using namespace std;


// 管理智能指针引用计数
template<typename T>
class ShareCount
{
private:
    T* ptr;     // 指向管理的对象
    int count;  // 引用计数

    // 禁止拷贝构造与赋值
    ShareCount(const ShareCount&) = delete; 
    ShareCount& operator= (const ShareCount&) = delete;

public:
    ShareCount(T *p) : ptr(p), count(1) {}
    ~ShareCount() {delete ptr};

    // 增加引用计数
    void increment(){
        count++;
    }

    // 减少引用计数
    void decrement() {
        if(--count == 0)
            delete this;
    }

    // 获取指向对象的原始指针
    T* getPtr(){
        return ptr;
    }
};

template<typename T>
class shared_ptr
{
private:
    T* ptr;     // 指向管理对象的指针
    ShareCount<T>* countPtr;    // 指向智能指针引用计数的类对象
public:
    shared_ptr(T* p = nullptr):ptr(p){
        if(p) {
            countPtr = new ShareCount<T> p;
        }
        else {
            p = nullptr;
        }
    }
    // 拷贝构造

    // 移动构造
    

    // 析构函数
    ~shared_ptr();
};



int main()
{

}