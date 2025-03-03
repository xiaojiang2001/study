#include <bits/stdc++.h>

using namespace std;

int maxValue(vector<vector<int> >& grid) 
{
    int m = grid.size();    // 行
    int n = grid[0].size(); // 列
    // dp[i][j]: 表示到达棋盘grid[i][j] 位置获取的最大礼物值为dp[i][j]
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 初始化dp
    dp[0][0] = grid[0][0];
    // 第一列
    for (size_t i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0]; 
    }
    // 第一行
    for (size_t j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    
    // 递推公式与遍历
    for (size_t i = 1; i < m; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
        }
    }
    
    // for (auto array: dp)
    // {
    //     for (auto num : array) {
    //         cout << num << " ";
    //     }
    //     cout << endl;       
    // }
    


    return dp[m-1][n-1];
}

int main()
{

}