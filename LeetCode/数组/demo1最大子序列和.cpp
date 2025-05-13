#include <bits/stdc++.h>

using namespace std;


// // 思路1: 贪心
// int maxSubArray(vector<int>& nums) 
// {
//     int maxSum = INT_MIN;
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//         maxSum = max(maxSum, sum);
//         // 贪心 一旦和为0，前面的肯定不加了
//         if(sum < 0)
//             sum = 0;
//     }
//     return maxSum;
// }

// dp[i]: 表示考虑当前下标i··组成的最大子数组和
int maxSubArray(vector<int>& nums) 
{
    if(nums.size() == 0)
        return 0;

    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int maxSum =  dp[0];

    for(int i = 0; i < nums.size(); i++) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}


int main()
{
    return 0;
}

