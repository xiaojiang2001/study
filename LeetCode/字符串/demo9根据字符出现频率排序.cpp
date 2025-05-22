#include <bits/stdc++.h>

using namespace std;



// umap统计 + vector排序
static bool cmp(const pair<char, int> &vec1, const pair<char, int> &vec2) {
    return vec1.second > vec2.second;
}
string frequencySort(string s) {
    unordered_map<char, int> umap;
    for (auto ch : s)
        umap[ch]++; // 统计字符频率

    vector<pair<char, int>> vec(umap.begin(), umap.end());
    sort(vec.begin(), vec.end(), cmp);

    string res = "";
    for (auto pair : vec) {
        for(int j = 0; j < pair.second; j++)
            res += pair.first;
    }

    return res;
}


// 利用优先级队列自动排序
// 大顶堆
class Cmp
{
public:
    bool operator() (const pair<char, int> &pair1, const pair<char, int> &pair2)
    {
        return pair1.second < pair2.second;
    }
};

string frequencySort(string s) {
    // 定义优先级队列，存储 pair<char, int>，按频率从高到低排序=
    priority_queue<pair<char, int>, vector<pair<char, int>>, Cmp> que;

    unordered_map<char, int> umap;
    for (auto ch : s)
        umap[ch]++; // 统计字符频率

    for (auto it : umap) {
        que.push({it.first, it.second});
    }

    string res = "";
    while (!que.empty())
    {
        auto pair = que.top();
        que.pop();
        res.append(pair.second, pair.first);    // 将字符重复 top.first 次
    }
    
    return res;
}