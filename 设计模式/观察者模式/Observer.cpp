#include "Observer.h"
#include "Publisher.h"

using namespace std;    

int main()
{
    // 发布者
    Publisher1* publisher1 = new Publisher1();
    Publisher2* publisher2 = new Publisher2();  
    // 订阅者
    Observer1* observer1 = new Observer1(publisher1, "Observer1");
    Observer2* observer2 = new Observer2(publisher1, "Observer2");
    Observer3* observer3 = new Observer3(publisher2, "Observer3");

    // 推送消息
    publisher1->notify("publisher1 notify message1");
    cout << "======================================" << endl;
    publisher2->notify("publisher2 notify message2");

    delete publisher1;
    delete publisher2;
    delete observer1;  
    delete observer2;
    delete observer3;
    
    return 0;
}