#include <bits/stdc++.h>

using namespace std;

// 哈希 + 排序
vector<string> topKFrequent(vector<string>& words, int k) 
{
    unordered_map<string, int> umap;
    for(auto word : words) {
        umap[word]++;
    }

    vector<string> vec;
    for (auto pair : umap) {
        vec.push_back(pair.first);
    }

    sort(vec.begin(), vec.end(), [&](const string &str1, const string &str2)->bool{
        return umap[str1]==umap[str2]? str1 < str2: umap[str1] > umap[str2];
    });
    vec.erase(vec.begin() + k, vec.end());
    return vec;
}


