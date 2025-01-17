#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin	>> n >> k;
	
	vector<int> grid(n+1, 0);
	int idx;
	while(k--) {
		cin >> idx;
		grid[idx] = 1;
	}
	
	
//	for(int i = 1; i <= n; i++)
//		cout << grid[i] << " ";
	// 最终返回终点: 对于长度为n的区间内的时间为 2n-2
	// 每个区域被清扫一次:  sum(clean[K+1]) >= N
	//   
	return 0;
 } 
