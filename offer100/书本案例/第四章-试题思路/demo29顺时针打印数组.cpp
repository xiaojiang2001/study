#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m = 4;
    int n = 4;
    vector<vector<int>> vec(m, vector<int>(n));
    int num = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           vec[i][j] = num++;
        }
    }
    int up = 0;
    int left = 0;
    int down = m - 1;
    int right = n -1;

    int idx = 0;
    vector<int> res(m * n);

    while (idx < m * n)
    {
        for (int j = left; j <= right; j++) {
            res[idx++] = vec[up][j];
        }
        up++;
        if(up > down)   break;

        for (int i = up; i <= down; i++) {
            res[idx++] = vec[i][right];
        }
        right--;
        if(right < left)       break;
        
        for (int j = right; j >= left; j--) {
            res[idx++] = vec[down][j];
        }
        down--;
        if(down < up)    break;

        for (int i = down; i >= up; i--) {
            res[idx++] = vec[i][left];
        }
        left++;
        if(left > right)   break;    
    }

    for (int i = 0; i < m * n; i++) 
    {
        cout << res[i] << " ";
    }
    
    return 0;
}