#include <bits/stdc++.h>

using namespace std;

// nums = [10,9,2,5,3,7,101,18]
int lengthOfLIS(vector<int>& nums) 
{
    // dp[i]: 表示以nums[i]结尾的最长递增子序列长度
    vector<int> dp(nums.size(), 1);         // 初始化为1

    for(int i = 1; i < nums.size(); i++)    // dp[0] 一定为1
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }     
    }
    return *max_element(dp.begin(), dp.end());
}