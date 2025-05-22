#include <iostream>
using namespace std;

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

// 工厂接口
class Factory {
public:
    virtual ~Factory() = default;
    virtual Product* createProduct() const = 0;
};

// 具体工厂类A
class ConcreteFactoryA : public Factory {
public:
    Product* createProduct() const override {
        return new ConcreteProductA();
    }
};

// 具体工厂类B
class ConcreteFactoryB : public Factory {
public:
    Product* createProduct() const override {
        return new ConcreteProductB();
    }
};

// 客户端代码
int main() {
    char type;
    cout << "Enter product type (A or B): ";
    cin >> type;

    Factory* factory = nullptr;
    if (type == 'A') {
        factory = new ConcreteFactoryA();
    } else if (type == 'B') {
        factory = new ConcreteFactoryB();
    } else {
        cerr << "Unknown product type" << endl;
        return 1;
    }

    Product* product = factory->createProduct();
    product->operation();
    
    delete product;  // 手动释放产品对象
    delete factory;  // 手动释放工厂对象

    return 0;
}