#include <bits/stdc++.h>

using namespace std;

// sum, left, nums[idx]，right = sum - left - nums[idx], left == right
int pivotIndex(vector<int>& nums) 
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        int rightSum = sum - nums[i] - leftSum;
        if (rightSum == leftSum)
            return i;
        leftSum += nums[i];
    }
    return -1;
}


// 滑动窗口
int pivotIndex(vector<int>& nums) {
    int leftSum = 0;
    int rightSum = 0;

    for (int i = 1; i < nums.size(); i++) {
        rightSum += nums[i];
    }

    int idx = 0;
    while (leftSum != rightSum)
    {
        if(idx + 1 == nums.size())
            return -1;
        leftSum += nums[idx];
        rightSum -= nums[idx + 1];
        idx++;
    }
    return idx;
}