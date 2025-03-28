#include <iostream>

class MyClass {
public:
  MyClass(int value) : data(value) {
    std::cout << "Constructor called: " << data << std::endl;
  }

  MyClass(const MyClass& other) : data(other.data) {
    std::cout << "Copy constructor called: " << data << std::endl;
  }

  int getData() const {
    return data;
  }

private:
  int data;
};

void doSomething(MyClass obj) {
  std::cout << "Data inside doSomething: " << obj.getData() << std::endl;
}

MyClass createObject(int value) {
  return MyClass(value);
}

int main() 
{
    MyClass obj1(10);
    // 对象作为函数参数时，调用拷贝构造
    doSomething(obj1);

    MyClass obj2 = createObject(20);
    std::cout << "Data inside main: " << obj2.getData() << std::endl;

  return 0;
}