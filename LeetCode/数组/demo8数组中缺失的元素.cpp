#include <bits/stdc++.h>

using namespace std;

// 使用uset查找 空间复杂度为O(n)
int missingNumber(vector<int>& nums) {
    unordered_set<int> uset;
    uset.insert(nums.begin(), nums.end());
    for(int i = 0; i <= nums.size(); i++)
    {
        if(uset.find(i) == uset.end())
            return i;
    }
    return -1;
}

// 异或 
// 可以异或就可以求和，但求和需要考虑sum越界问题
int missingNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res ^= i;
        res ^= nums[i];
    }
    res ^= nums.size();
    return res;
}
