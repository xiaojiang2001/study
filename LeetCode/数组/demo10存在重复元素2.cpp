#include <bits/stdc++.h>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
        // 数值第一次出现
        if(umap.find(nums[i]) == umap.end()) {
            umap.insert({nums[i], i});
        }
        // 数值出现过
        else
        {
            if(i - umap[nums[i]] <= k)  // 存在
                return true;
            else
                umap[nums[i]] = i;      // 更新值的下标
        }
    }
    return false;
}