#include <bits/stdc++.h>

using  namespace std;

/*******************插入排序************************/
class Solution {
public:
    void Insert(int num) {
        if(array.empty()) {
            array.push_back(num);
        }
        else
        {
            auto it = array.begin();
            for ( ; it < array.end(); it++) {
                if(num <= *it)
                    break;
            }
            array.insert(it, num);
        }
    }

    double GetMedian() { 
        int size = array.size();
        double res;
        // 获取中间值
        if(size % 2 == 1)
            res = array[size / 2] * 1.0;
        else
            res = (array[size / 2] + array[size / 2 - 1]) / 2.0;
        return res;
    }
private:
    vector<int> array;
};

/****************堆排序**************************/
class smallHeap{
public:
    // 小顶堆
    bool operator()(const int l, const int r)
    {
        return l > r;
    }
};
class largeHeap{
public:
    // 小顶堆
    bool operator()(const int l, const int r)
    {
        return l < r;
    }
};

class Solution2{
public:
    void Insert(int num) {
        small_queue.push(num);
        if(!large_queue.empty() && small_queue.top() > large_queue.top())
        {
            large_queue.push(small_queue.top());
            small_queue.pop();
            small_queue.push(large_queue.top());
            large_queue.pop();
        }
        if(small_queue.size() - large_queue.size() > 1)
        {
            large_queue.push(small_queue.top());
            small_queue.pop();
        }
    }

    double GetMedian() { 
        if(small_queue.size() > large_queue.size())
            return small_queue.top() * 1.0;
        else
        {
            return (small_queue.top() + large_queue.top()) / 2.0;
        }
    }
private:
    priority_queue<int, vector<int>, smallHeap> large_queue;    // 大顶堆，存放小的数，堆顶是最大的数，接近中间值  4 3 2 1
    priority_queue<int, vector<int>, largeHeap> small_queue;    // 小顶堆，存放大的数，堆顶是最小的数，接近中间值  5 6 7 8 
};

int main()
{
    Solution2 s;
    vector<int> input{5,2,3,4,1,6,7,0,8};
    for (auto num : input)
    {
        s.Insert(num);
        cout << fixed <<  setprecision(2) << s.GetMedian() << endl;
    }
    return 0;
}