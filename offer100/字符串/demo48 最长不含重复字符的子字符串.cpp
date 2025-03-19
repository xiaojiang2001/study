#include <bits/stdc++.h>

using namespace std;

// cababcabc
int lengthOfLongestSubstring(string s) 
{
    int hash[256] = {0};
    int fast = 0;
    int slow = 0;
    int res = 0;
    while (fast < s.size())
    {
        // 遇到重复的了
        if(hash[s[fast]] == 1) {
            while (slow < s.size() && s[slow] != s[fast]) {
                hash[s[slow]] = 0;
                slow++;
            }
            slow++;
        }
        // 不重复
        else {
            hash[s[fast]] = 1;
            res = max(res, fast- slow + 1);
        }
        fast++;
    }
    return res;
}

int main()
{
    string s = "abcabcabb";
    int res = lengthOfLongestSubstring(s);
    cout << "res:" << res << endl;
    return 0;
}