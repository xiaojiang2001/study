#include <bits/stdc++.h>

using namespace std;


// 检查字符中的某一个段是否为字符串
bool isPalindrome(string s, int start, int end)
{
    if(s == "") return true;
    while (start < end)
    {
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        // 不相等了 准备删除元素, 判断两边
        if(s[i] != s[j]) {
            bool left  = isPalindrome(s, i, j-1);
            bool right = isPalindrome(s, i+1, j);
            if(left || right)
                return true;
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int main()
{

}