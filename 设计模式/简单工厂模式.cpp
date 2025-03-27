#include <bits/stdc++.h>

using namespace std;

// 从而实现对象的解耦合, 同时增强了程序的扩展性
// 抽象产品接口
class Product {
public:
    virtual ~Product() = default;
    virtual void operation() const = 0;
};

// 具体产品类A
class ConcreteProductA : public Product {
public:
    void operation() const override {
        cout << "ConcreteProductA operation" << endl;
    }
};

// 具体产品类B
class ConcreteProductB : public Product {
public:
    void operation() const override {
        cout << "ConcreteProductB operation" << endl;
    }
};

// 工厂类
class SimpleFactory {
public:
    static Product* createProduct(char type) {
        if (type == 'A') {
            return new ConcreteProductA();
        } else if (type == 'B') {
            return new ConcreteProductB();
        } else {
            throw invalid_argument("Unknown product type");
        }
    }
};

// 客户端代码
int main() {
    char type;
    cout << "Enter product type (A or B): ";
    cin >> type;

    Product* product = SimpleFactory::createProduct(type);
    product->operation();
    delete product;  // 手动释放内存
 

    return 0;
}