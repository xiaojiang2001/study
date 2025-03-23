#include <bits/stdc++.h>

using namespace std;


// 单调队列 - 维护有可能成为最大值的序列
class Deque
{
private:
    deque<int> que;

public:
    int getMax();
    void push(int x);
    void pop(int x);
    void push_back(int val);
};

int Deque::getMax()
{
    return que.front();
}

void Deque:: push(int val)
{
    while(!que.empty() && val > que.back()) {
        que.pop_back();
    }
    que.push_back(val);
}

void Deque:: push_back(int val)
{
    que.push_back(val);
}

void Deque::pop(int val)
{
    if(!que.empty() && val == que.front())
        que.pop_front();
}

vector<int> maxInWindows(vector<int>& num, int size) {
    Deque que;
    vector<int> ret;
    if (num.size() == 0 || size < 1 || num.size() < size) 
        return ret;

    for (int i = 0; i < size; i++) {
        que.push(num[i]);
    }
    // // ret 记录前size的元素的最大值
    // ret.push_back(que.getMax());

    // 形成队列
    for (int i = size -1 ; i < num.size(); i++)
    {
        que.pop(num[i - size]);         // 滑动窗口移除最前面元素
        que.push(num[i]);               // 滑动窗口前加入最后面的元素     
        ret.push_back(que.getMax());    // 记录对应的最大值
    }
    
    return ret;
}

int main()
{

}