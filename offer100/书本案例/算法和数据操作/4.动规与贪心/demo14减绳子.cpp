#include <bits/stdc++.h>

using namespace std;


int cutRope(int n) 
{

    vector<int> dp(n+1, 0);
    if(n < 2)       return 0;
    if(n == 2)      return 1;
    if(n == 3)      return 2;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {   
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], dp[j] * dp[i-j]);
        }
    }

    return dp[n];
}

int main()
{
    return 0;
}