#include <bits/stdc++.h>

using namespace std;

// [start, end]
void swapStr(string& str, int start, int end)
{
    if(str.size() <= 1 || start < 0 || end >= str.size() || end <= start)
        return;

    int i = start;
    int j = end;
    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

string reverseWords(string s) {
    int i = 0;
    int j = 0;
    string subStr = s.substr(i, j - i + 1);
    while (s[j] != '\0')
    {
        // 找到空格 翻转
        if(s[j] == ' ') {
            swapStr(s, i, j - 1);
            i = j + 1;
        }
        j++;
    }   
    swapStr(s, i, j - i);
    return s;
}

