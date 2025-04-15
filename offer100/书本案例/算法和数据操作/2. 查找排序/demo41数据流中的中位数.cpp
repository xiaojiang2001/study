#include <bits/stdc++.h>

using namespace std;

class cmp_max {
public:
    bool operator()(const int l, const int r)
    {
        return l < r;
    }
};

class cmp_min {
public:
    bool operator()(const int l, const int r)
    {
        return l > r;
    }
};

class Solution {
public:
    void Insert(int num) 
    {
        // O(logn)
        // 优先放大顶堆 小的数
        if(maxQue.size() == minQue.size()) {
            if(!minQue.empty() && num > minQue.top()) {
                maxQue.push(minQue.top());
                minQue.pop();
                minQue.push(num);
            }
            else
                maxQue.push(num);
        }

        else {
            if(!maxQue.empty() && num < maxQue.top()) {
                minQue.push(maxQue.top());
                maxQue.pop();
                maxQue.push(num);
            }
            else
                minQue.push(num);
        }
    }

    double GetMedian() { 
        // O(1)
        if(maxQue.size() > minQue.size())
            return maxQue.top() * 1.0;
        
        return (maxQue.top() + minQue.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>, cmp_max> maxQue;     // 大顶堆, 存放小的数
    priority_queue<int, vector<int>, cmp_min> minQue;     // 小顶堆, 存放大的数
};


int main()
{
    return 0;
}