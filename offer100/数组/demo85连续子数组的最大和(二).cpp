#include <bits/stdc++.h>

using namespace std;

vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
    vector<int> res;    // 结果集
    vector<int> path;   // 当前路径结果
    int maxLen = 0;     // 最长长度
    int sum = 0;        // 当前和
    int maxSum = 0;     // 最大和

    for (size_t i = 0; i < array.size(); i++)
    {
        sum += array[i];
        path.push_back(array[i]);

        // 获取最大值
        if(sum > maxSum || sum == maxSum &&  path.size() > maxLen) {
            maxSum = sum;
            maxLen = path.size();
            res = path;
            path.clear();
        }
        // 贪心 忽略全部
        if(sum < 0) {
            res.clear();
            sum = 0;
        }
    }
    return res;
}

vector<int> FindGreatestSumOfSubArray2(vector<int>& array) 
{
    // dp[i]: 表示加到当前元素的连续子数组的最大和为dp[i]
    vector<int> dp(array.size(), 0);
    return array;
}



int main()
{
    vector<int> array{1,-2,3,10,-4,7,2,-5};
    vector<int> res = FindGreatestSumOfSubArray(array);
    for (auto num : res)
        cout << num << " ";
    cout << endl;
    return 0;
}