#include <iostream>

// 旧接口
class OldInterface {
public:
    virtual void oldRequest() = 0;
};

// 旧接口的具体实现
class OldImplementation : public OldInterface {
public:
    void oldRequest() override {
        std::cout << "OldImplementation: Handling request." << std::endl;
    }
};

// 新接口
class NewInterface {
public:
    virtual void newRequest() = 0;
};

// 适配器类
class Adapter : public NewInterface {
private:
    OldInterface* oldInterface;
public:
    Adapter(OldInterface* oldInterface) : oldInterface(oldInterface) {}

    void newRequest() override {
        // 调用旧接口的方法来实现新接口的方法
        oldInterface->oldRequest();
    }
};

// 客户端代码
int main() {
    OldInterface* oldInterface = new OldImplementation();
    NewInterface* newInterface = new Adapter(oldInterface);

    newInterface->newRequest();

    delete oldInterface;
    delete newInterface;

    return 0;
}