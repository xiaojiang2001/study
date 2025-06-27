#include <bits/stdc++.h>

using namespace std;

vector<int> path;
vector<vector<int>> res;

/*
// 全排列 给定一个不含重复数字的数组 nums ，返回其所有可能的全排列。
void backtracking(vector<int>& num, vector<bool>& used)
{
    if(path.size() == num.size()) {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < num.size(); i++)
    {
        if(used[i]) 
            continue;

        path.push_back(num[i]);
        used[i] = true;
        backtracking(num, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    path.clear();
    res.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}
*/

// 全排列2 给定一个可包含重复数字的序列nums ，按任意顺序 返回所有不重复的全排列
void backtracking(vector<int>& nums, vector<bool> used)
{
    if(path.size() == nums.size()) {
        res.push_back(path);
        return;
    } 

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(used[i] == true) continue;       // 排列，用过的不用
        if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;   // 去重

        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    path.clear();
    res.clear();
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}



void print_vec(const vector<vector<int>>& vec)
{
    for (auto path : vec) {
        for (auto it : path) {
            cout << it << " ";
        }
        cout << endl;
    }  
}
int main()
{
    vector<int> nums{3,3,0,3};
    vector<vector<int>> vec = permuteUnique(nums);
    print_vec(vec);
    return 0;
}