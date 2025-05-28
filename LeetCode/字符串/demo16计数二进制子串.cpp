#include <bits/stdc++.h>

using namespace std;

int countBinarySubstrings(string s) 
{
   int cnt = 1;
   vector<int> nums;
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1]) {
            cnt++;
        }
        else {
            nums.push_back(cnt);
            cnt = 1;           
        }
    }
    nums.push_back(cnt);

    int ans = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        ans += min(nums[i], nums[i+1]);
    }
    
    return ans;
}
int main()
{
    string s = "10101";
    countBinarySubstrings(s);
}