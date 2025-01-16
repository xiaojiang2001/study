#include <bits/stdc++.h>

using namespace std;


int jumpFloor(int number) 
{
    // dp[i] : 表示跳上i阶段台阶有dp[i]种跳法
    vector<int> dp(number+1,0);
    dp[1] = 1;
    dp[2] = 2;
    for (int  i = 3; i <= number; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[number];
}


int main()
{
    
    int n;
    cin >> n;
    

    
    return 0;
}