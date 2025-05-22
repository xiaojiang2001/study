#include <bits/stdc++.h>

using namespace std;


// 判断一个区间内字符串是否为回文串
bool valid(string s, int left, int right) {
    while (left <= right) {
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left <= right)
    {
        if(s[left] != s[right]) {
            bool leftValid = valid(s, left, right - 1);
            bool rightValid = valid(s, left + 1, right);
            if(leftValid == true || rightValid == true)
                return true;
            else
                return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{

}