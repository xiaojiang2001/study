#include <bits/stdc++.h>

using namespace std;

vector<int> path;
vector<vector<int>> res;

// 组合1，输入n个数中的k个组合  4 2
/*
void backtracking(int n, int k, int startIdx)
{
    if(path.size() == k) {
        res.push_back(path);
        return;
    }

    for (size_t i = startIdx; i <= (n- k + path.size()); i++)
    {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    path.clear();
    res.clear();
    backtracking(n, k, 1);
    return res;
}
*/


// 组合3，找出所有相加之和为 n 的 k 个数的组合
/*
void backtracking(int k, int n, int startIdx, int sum)
{
    if(sum > n)
        return;
    if(path.size() == k)
    {
        if(sum == n)
            res.push_back(path);
        return;
    }

    for (int i = startIdx; i <= 9 - (k - path.size()) + 1; i++)
    {
        path.push_back(i);
        sum += i;
        backtracking(k ,n , i + 1, sum);
        path.pop_back();
        sum -= i;
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    path.clear();
    res.clear();
    backtracking(k, n, 1, 0);
    return res;
}
*/

// 组合总和1  元素可使用多次
// 无重复元素 的整数数组 candidates 和一个目标整数 target ，
// 找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合
/*
void backtracking(const vector<int>& candidates, int target, int stratIdx, int sum)
{
    if(sum > target)    return;
    else if(sum == target) {
        res.push_back(path);
        return;
    }

    for (int i = stratIdx; i < candidates.size(); i++)
    {
        path.push_back(candidates[i]);
        sum += candidates[i];
        backtracking(candidates, target, i, sum);
        sum -= candidates[i];
        path.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    path.clear();
    res.clear();
    backtracking(candidates, target, 0, 0);
    return res;
}
*/



// 组合总和2 同上，candidates 中的每个数字在每个组合中只能使用一次 
void backtracking(vector<int>& candidates, int target, int startIdx, int sum, vector<bool>& used)
{
    if(sum > target)    return;
    else if(sum == target) {
        res.push_back(path);
        return;
    }

    for (int i = startIdx; i < candidates.size(); i++)
    {
        // 去重
        if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
            continue;
        
        path.push_back(candidates[i]);
        sum += candidates[i];
        used[i] = true;
        backtracking(candidates, target, i + 1,  sum,  used);
        path.pop_back();
        sum -= candidates[i];
        used[i] = false;
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    path.clear();
    res.clear();
    sort(candidates.begin(), candidates.end());
    vector<bool> used(candidates.size(), false);
    backtracking(candidates, target, 0, 0, used);
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
    vector<int> candidates{10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> vec = combinationSum2(candidates, target);
    print_vec(vec);
    return 0;
}