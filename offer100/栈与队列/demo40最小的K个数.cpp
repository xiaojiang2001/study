#include <bits/stdc++.h>

using namespace std;


class cmp
{
public:
    // 大顶堆
    bool operator()(const int l, const int r)
    {
        return l < r;
    };
};

vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
    priority_queue<int, vector<int>, cmp> pri_que;
    for (auto num : input) {
        pri_que.push(num);
        if(pri_que.size() > k)
            pri_que.pop();
    }
    
    // 收集结果
    vector<int>  res;
    while (!pri_que.empty()) {
        res.push_back(pri_que.top());
        pri_que.pop();
    }
    return res;
}
int main()
{
    vector<int> input{4,5,1,6,2,7,3,8};
    vector<int> res = GetLeastNumbers_Solution(input, 4);
    for (auto num : res)
    {
        cout << num << endl;
    }
    return 0;
}