#include <iostream>

using namespace std;

class Base {
public:
    virtual void sayHello() {
        std::cout << "Hello from Base class!" << std::endl;
    }
    void print(){
        cout << "print from Base class!" << std::endl;
    }
};

class Derived : public Base {
public:
    void sayHello() override {  // 使用 override 关键字表明重写了父类的函数
        std::cout << "Hello from Derived class!" << std::endl;
    }

    void print(){
        cout << "print from Derived class!" << std::endl;
    }
};

int main() 
{
    Base* basePtr = new Derived();
    basePtr->sayHello();
    delete basePtr;
    basePtr = nullptr;

    Derived* derivedPtr = new Derived();
    derivedPtr->sayHello();
    delete derivedPtr;
    derivedPtr = nullptr;

    return 0;
}