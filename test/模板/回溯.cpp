#include <bits/stdc++.h>

using namespace std;

void showDoubleVec(const vector<vector<int>>& vec);


vector<int> path;
vector<vector<int>> res;

// 组合总和 不需要去重
// 输入：nums=[2,3,5], target = 8,
// 输出: [[2,2,2,2],[2,3,3],[3,5]]
void backtracking1(vector<int>nums, int target, int sum, int startIdx)
{
    if(sum > target)
        return;

    if(sum == target) {
        res.push_back(path);
        return;
    }

    for (int i = startIdx; i < nums.size(); i++)
    {
        sum += nums[i];
        path.push_back(nums[i]);
        backtracking1(nums, target, sum, i + 1);     // 不可重复使用数字
        // backtracking1(nums, target, sum, i);         // 可重复使用数字

        sum -= nums[i];
        path.pop_back();
    }
    return;
}


// 集合有重复元素，但还不能有重复的组 需要去重嘛
// 输入: candidates = [2,5,2,1,2], target = 5,
// [1,2,2],[5]
void backtracking2(vector<int>nums, int target, int sum, int startIdx, vector<bool>& used)
{
    if(sum > target)
        return;

    if(sum == target) {
        res.push_back(path);
        return;
    }


    for (int i = startIdx; i < nums.size(); i++)
    {
        // // 去重 逻辑非常关键
        // if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
        //     continue;

        sum += nums[i];
        path.push_back(nums[i]);
        used[i] = true;
        backtracking2(nums, target, sum, i + 1, used);     
        sum -= nums[i];
        path.pop_back();
        used[i] = false;
    }
    return;
}

// 全排列2 去重 这是排列
// 输入：nums = [1,1,2]
// 输出： [[1,1,2], [1,2,1], [2,1,1]]
void backtracking3(const vector<int>& nums, vector<bool>& used)
{
    if(path.size() == nums.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        // 排列 使用过的当然不用了
        if(used[i] == true)
            continue;

        // 字符去重
        if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            continue;

        path.push_back(nums[i]);
        used[i] = true;
        backtracking3(nums, used);
        path.pop_back();
        used[i] = false;
    }
    return;
}


int main()
{
    vector<int> nums{1,1,2};
    int target = 5;
    res.clear();
    path.clear();
    sort(nums.begin(), nums.end());             // 去重才需要先排序
    vector<bool> used(nums.size(), false);
    backtracking3(nums, used);
    showDoubleVec(res);
    return 0;
}


void showDoubleVec(const vector<vector<int>>& vec)
{
    for (auto subVec: vec) {
        for (auto num : subVec) {
            cout << num << " ";
        }
        cout << endl;
    }
    
}