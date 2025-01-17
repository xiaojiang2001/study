#include <bits/stdc++.h>
using namespace std;

// ☆当 n >= 20时，结果不变 
int main()
{
	vector<int> dp(31, 0);
	dp[1] = dp[2] = 1;
	for(int i = 3; i <= 30; i++)
		dp[i] = dp[i-1] + dp[i-2];

	int n;
	cin >> n;
	if(n >= 20)
		n = 20;
		
	double res = dp[n] * 1.0 / dp[n+1];
	cout << fixed << setprecision(8) << res << endl;	
	return 0; 
} 
