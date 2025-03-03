#include <bits/stdc++.h>

using namespace std;

int jumpFloorII(int number) 
{
    // 背包大小 num
    // 物品大小 1-num
    // 多重背包 组合数
    // dp[i]: 表示跳上台阶number有dp[i]种方法
    vector<int> dp(number + 1, 0);
    dp[0] = dp[1] = 1;
    for (size_t i = 1; i <= number; i++)
    {
                
    }
}

int jumpFloorII(int number) 
{
    // f(n) = f(n-1) + f(n-2) + ... + f(2) + f(1) + f(0)
    // f(n-1) = f(n-2) + ... + f(2) + f(1) + f(0)
    // f(n) = f(n-1) * 2
    // f[0] = 1 f[1] = 1 f[2] = 2 f[3] = 4   f[4] = 8
    return pow(2, number-1);
}



int main()
{

}