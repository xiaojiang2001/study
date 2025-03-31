#include <iostream>
#include <string>

// 主题接口
class Subject {
public:
    virtual void request() = 0;
};

// 真实主题类
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// 代理类
class Proxy : public Subject {
private:
    RealSubject* realSubject;
    std::string accessControlToken;

    bool checkAccess() {
        std::cout << "Proxy: Checking access prior to firing a real request." << std::endl;
        return accessControlToken == "valid_token";
    }

    void logAccess() {
        std::cout << "Proxy: Logging the time of request." << std::endl;
    }

public:
    Proxy(RealSubject* realSubject, const std::string& token) : realSubject(realSubject), accessControlToken(token) {}

    void request() override {
        if (checkAccess()) {
            realSubject->request();
            logAccess();
        } else {
            std::cout << "Proxy: Access denied." << std::endl;
        }
    }
};

// 客户端代码
int main() {
    RealSubject* realSubject = new RealSubject();
    Proxy* proxy = new Proxy(realSubject, "valid_token");

    proxy->request();

    delete realSubject;
    delete proxy;

    return 0;
}