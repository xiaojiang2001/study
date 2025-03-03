#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int hash[26] = {0};
    int fast = 0;
    int slow = 0;
    while (fast < s.size())
    {
        // 遇到重复的了
        if(hash[s[fast] - 'a'] == 1) {
            slow++;
            fast++;
        }
        // 不重复
        else {
            hash[s[fast] - 'a'] = 1;
            fast++;
        }
    }
    return fast - slow;
}

int main()
{
    string s = "abcabcabb";
    int res = lengthOfLongestSubstring(s);
    cout << "res:" << res << endl;
    return 0;
}