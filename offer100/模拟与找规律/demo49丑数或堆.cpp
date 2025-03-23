#include <bits/stdc++.h>

using namespace std;

int GetUglyNumber_Solution(int index) 
{
    if(index == 1)
        return 1;

    // 存放第i个丑数
    vector<long long> dp(index + 1);
    dp[1] = 1;
    long long p2 = 1;
    long long p3 = 1;
    long long p5 = 1;

    for (int i = 2; i <= index; i++)
    {
        dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5)); 
        if(dp[i] == p2 * 2)  p2++;
        if(dp[i] == p3 * 3)  p3++;
        if(dp[i] == p5 * 5)  p5++;
    }

    return dp[index];
}

int main()
{

    return 0;
}