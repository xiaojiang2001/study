#include <bits/stdc++.h>

using namespace std;

vector<int> path;
vector<vector<int>> res;

/*
void backtracking(vector<int>& nums, int startIdx)
{
    if(path.size() > nums.size())
        return;
    
    for (int i = startIdx; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        res.push_back(path);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    path.clear();
    res.clear();
    res.push_back(vector<int> {});
    backtracking(nums, 0);
    return res;
}
*/




void backtracking(vector<int>& nums, int startIdx, vector<bool>& used)
{
    res.push_back(path);

    if(path.size() >= nums.size())
        return;

    for (int i = startIdx; i < nums.size(); i++)
    {
        if(i > 0 && nums[i] == nums[i-1] && used[i - 1] == false)
            continue;

        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, i + 1, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    path.clear();
    res.clear();
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, 0, used);
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
    vector<int> nums{1,2,2};
    vector<vector<int>> vec = subsetsWithDup(nums);
    print_vec(vec);

    return 0;
}