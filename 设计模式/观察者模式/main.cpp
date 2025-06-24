#include "Observer.h"
#include "Publisher.h"

using namespace std;    

int main()
{
    // 发布者
    Publisher1* publisher1 = new Publisher1("publisher1");
    Publisher2* publisher2 = new Publisher2("publisher2");  
    // 订阅者
    Observer1* observer1 = new Observer1("Observer1", publisher1);
    Observer2* observer2 = new Observer2("Observer2", publisher1);
    Observer3* observer3 = new Observer3("Observer3", publisher2);

    // 推送消息
    publisher1->notify("publisher1 notify message1");
    cout << "======================================" << endl;
    publisher2->notify("publisher2 notify message2");
        
    return 0;
}