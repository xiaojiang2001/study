#ifndef __OBSERVER_H__
#define __OBERVER_H__

#include <iostream>
#include "Publisher.h"
#include <string>
#include <algorithm>

using namespace std;

class Publisher;

// 抽象观察者类
class Observer {
public:

    // 只创建观察者，不订阅
    Observer(const std::string& name);

    // 支持只订阅一个发布者的构造
    Observer(const std::string& name, Publisher* publisher);

    // 支持订阅多个发布者
    Observer(const std::string& name, const std::list<Publisher*>& publishers);
    
    virtual ~Observer();

    // 添加订阅指定发布者
    void subscribe(Publisher* publisher);

    // 取消订阅所有发布者
    void unsubscribeAll();

    // 取消订阅指定发布者
    void unsubscribe(Publisher* publisher);
    

    // 更新消息
    virtual void update(Publisher* publisher, string msg) = 0;


protected:
    list<Publisher*> m_publishers;      // 订阅的发布者列表
    string m_name;                      // 观察者名称
};



// 具体实现
class Observer1 : public Observer {
public:
    Observer1(string name, Publisher* publisher) : Observer(name, publisher) {
        cout << name << " is created" << endl;
    }

    void update(Publisher* publisher, string msg) override {
        cout << m_name << " received msg form " << publisher->getName()  << ": " << msg << endl;
    }

    ~Observer1() {
        cout << m_name << " is destroyed";
    }
};

class Observer2 : public Observer {
public:
    Observer2(string name, Publisher* publisher) : Observer(name, publisher) {
        cout << name << " is created" << endl;
    }

    void update(Publisher* publisher, string msg) override {
        cout << m_name << " received msg form " << publisher->getName()  << ": " << msg << endl;
    }

    ~Observer2() {
        cout << m_name << " is destroyed";
    }
};

class Observer3 : public Observer {
public:
    Observer3(string name, Publisher* publisher) : Observer(name, publisher) {
        cout << name << " is created" << endl;
    }

    void update(Publisher* publisher, string msg) override {
        cout << m_name << " received msg form " << publisher->getName() << ": " << msg << endl;
    }

    ~Observer3() {
        cout << m_name << " is destroyed";
    }
};

#endif