#include "Publisher.h"
#include "Observer.h"
#include <iostream>

using namespace std;

Publisher::Publisher(string name):m_name(name)
{

}

// 1. 添加订阅者
void Publisher::attach(Observer* observer)
{
    m_observers.push_back(observer);
}

// 2. 删除订阅者
void Publisher::detach(Observer* observer)
{
    // 删除
    m_observers.remove(observer);
}


Publisher1::Publisher1(string name):Publisher(name)
{

}

Publisher2::Publisher2(string name):Publisher(name)
{
    
}

void Publisher1::notify(string msg)
{
    cout << this->m_name <<" observer num:" << m_observers.size() <<endl;

    for(const auto &observer : m_observers)
    {
        // 观察者更新数据
        observer->update(this,msg);
    }
}


void Publisher2::notify(string msg)
{
    cout << this->m_name <<" observer num:" << m_observers.size() <<endl;

    for(const auto &observer : m_observers)
    {
        // 观察者更新数据
        observer->update(this,msg);
    }
}
