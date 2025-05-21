#include <bits/stdc++.h>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) 
{
    // dp[i]: 表示以nums[i]结尾的最长递增子序列长度
    vector<int> dp(nums.size(), 1);         // 初始化为1

    for(int i = 1; i < nums.size(); i++)    // dp[0] 一定为1
    {
        if(nums[i] > nums[i-1])
            dp[i] = dp[i-1] + 1; 
    }
    return *max_element(dp.begin(), dp.end());
}


// 直接模拟
int findLengthOfLCIS(vector<int>& nums) 
{
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return 1;

    int length = 1;
    int res = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i] < nums[i+1])
            length++;
        else
            length = 1;
        res = max(length, res);
    }
    return res;
}

// 滑动窗口
int findLengthOfLCIS(vector<int>& nums) 
{
    int start = 0;
    int end = 1;
    int length = 1;
    while (end < nums.size()) {
        if (nums[end] <= nums[end - 1])
            start = end; 
        length = max(length, end - start + 1);
        end++;  
    }
    return length;
}