#include <bits/stdc++.h>

using namespace std;

int cutRope(int n) {
    //长度为n的绳子剪后的最大乘积
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        for (int j = 1; j <= i/2; j++) {
            dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
        }
    }
    return dp[n];
}

int main()
{

}