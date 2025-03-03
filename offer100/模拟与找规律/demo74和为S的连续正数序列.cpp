#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> res;
vector<int> path;

void backtracking(int sum, int startIdx, int tempSum)
{
    if(tempSum > sum) {
        return;
    }
    if(tempSum == sum) {
        res.push_back(path);
        return;
    }

    for (int  i = startIdx; i <= sum / 2; i++)
    {
        // 计算
        tempSum += i;
        path.push_back(i);
        // 递归
        backtracking(sum, startIdx + 1, tempSum);
        // 回溯
        tempSum -= i;
        path.pop_back();
    }
}

vector<vector<int> > FindContinuousSequence(int sum) {
    res.clear();
    path.clear();
    backtracking(sum, 0, 0);
    return res;
}

int main()
{


    return 0;
}