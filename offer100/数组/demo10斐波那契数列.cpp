#include <bits/stdc++.h>

using namespace std;


int Fibonacci(int n) 
{
    vector<int> dp(n+1);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int res = Fibonacci(n);
    cout  << res << endl;
    return 0;
}