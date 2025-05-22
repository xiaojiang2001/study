#include <bits/stdc++.h>

using namespace std;




// 模拟单词
int countSegments(string s) {
    if(s == "")
        return 0;
    int cnt = 0;
    int i = 0;
    while (i < s.size())
    {
        // 找到第一个字母
        while(i < s.size() && s[i] == ' ')
            i++;
        if(i < s.size()) {
            cnt++;
            // 找到第一个空格
            while(i < s.size() && s[i] != ' ')
                i++;
        }
    }
    return cnt;
}

// 思路2: 统计前一个为空格且自身不是空格的数量即可 注意s[0]
int countSegments(string s) 
{
    if(s == "")
        return 0;
    int cnt = s[0]==' '? 0 : 1;
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i-1] == ' ' && s[i] != ' ')
            cnt++;
    }
    return cnt;
}