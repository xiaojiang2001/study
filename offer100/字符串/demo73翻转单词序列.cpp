#include <bits/stdc++.h>

using namespace std;

string ReverseSentence(string str) 
{
    // "nowcoder. a am I"
    reverse(str.begin(), str.end());    // "I ma . redocwon";
    int start = 0;      // 起始指针
    int end = 0;        // 尾指针   
    for (int i = 0; i < str.size(); i++)
    {
        // 遇到空格 旋转
        if(str[i] == ' '){
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
        end++;
    }
    // 翻转最后一个单词
    reverse(str.begin() + start, str.begin() + end);    
    return str;
}

int main()
{
    string str = "";
    string res = ReverseSentence(str);
    cout << res << endl;
    return 0;
}