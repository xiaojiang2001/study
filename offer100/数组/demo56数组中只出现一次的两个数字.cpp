#include <bits/stdc++.h>

using namespace std;

vector<int> FindNumsAppearOnce(vector<int>& nums) 
{
    unordered_set<int> uset;
    for (size_t i = 0; i < nums.size(); i++)
    {
        // 元素没有重复出现过
        if(uset.find(nums[i]) == uset.end())
            uset.insert(nums[i]);
        else    // 出现了第二次
            uset.erase(nums[i]);
    }
    // 收集结果
    vector<int> res;
    for (auto num : uset) {
        res.push_back(num);
    }
    // 非降序
    sort(res.begin(), res.end());
    return res;   
}


int main()
{

    return 0;
}