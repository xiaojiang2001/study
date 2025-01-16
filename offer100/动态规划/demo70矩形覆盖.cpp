#include <bits/stdc++.h>

using namespace std;

// 其实就是斐波那契数列
int rectCover(int number) 
{
    // dp[i] : 表示覆盖2*number的大矩形有dp[i]种方法
    vector<int> dp(number + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= number; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[number];
}

int main()
{

    return 0;
}   