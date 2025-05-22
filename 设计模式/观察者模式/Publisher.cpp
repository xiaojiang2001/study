#include "Publisher.h"
#include "Observer.h"
#include <iostream>

using namespace std;

Publisher::Publisher()
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


Publisher1::Publisher1()
{

}

Publisher2::Publisher2()
{
    
}

void Publisher1::notify(string msg)
{
    cout << "Publisher1 observer num:" << m_observers.size() <<endl;

    for(const auto &observer : m_observers)
    {
        // 观察者更新数据
        observer->update(msg);
    }
}


void Publisher2::notify(string msg)
{
    cout << "Publisher2 observer num:" << m_observers.size() <<endl;

    for(const auto &observer : m_observers)
    {
        // 观察者更新数据
        observer->update(msg);
    }
}
