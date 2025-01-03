#include <bits/stdc++.h>

using namespace std;

vector<int> reOrderArray(vector<int>& array) 
{
    queue<int> que;
    // 获取数组中的偶数 移除 入队列 加入数组
    for (auto  iter = array.begin(); iter != array.end(); )
    {
        if(*iter % 2 == 0) {
            que.push(*iter);
            array.erase(iter);
        }
        else
            iter++;
    }

    // 队列中的偶数放数组后面
    while (!que.empty()) {
        array.push_back(que.front());
        que.pop();
    }
    return array;
}



int main()
{
    vector<int> array{1,3,5,6,7};
    vector<int> res = reOrderArray(array);
    for (auto item : res)
        cout << item << " ";
    return 0;
}