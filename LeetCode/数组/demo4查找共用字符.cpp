#include <bits/stdc++.h>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    if(words.empty())
        return vector<string> {""};

    int hash[26];
    // 统计第一个单词字母的频率
    for(int i = 0; i < words[0].size(); i++)
        hash[words[0][i] - 'a']++;

    int hashTemp[26];
    for(int i = 1; i < words.size(); i++)
    {
        // 计算每个单词的hash 先清空hashTemp
        memset(hashTemp, 0, sizeof(int) * 26);
        for(int j = 0; j < words[i].size(); j++) {
            hashTemp[words[i][j] - 'a']++;
        }

        // 更新结果hash表
        for (int j = 0; j < 26; j++) {
            hash[j] = min(hash[j], hashTemp[j]);
        }
    }

    vector<string> res;
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] != 0)
        {
            hash[i]--;
            string s(1, i + 'a');
            res.push_back(s);
        }
    }

    return res;
}
