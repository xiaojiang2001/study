#include <bits/stdc++.h>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix)
{
    if(matrix.size() == 0)
        return vector<int>{};
    
    int up = 0;
    int left = 0;
    int down = matrix.size() - 1;
    int right = matrix[0].size() - 1;
    vector<int> res(matrix.size() * matrix[0].size());
    int idx = 0;

    while (left <= right && up <= down)
    {
        for (int i = left; i <= right; i++) {
            res[idx++] = matrix[up][i];
        }
        up++;
        if(up > down)    break;

        for (int i = up; i <= down; i++) {
            res[idx++] = matrix[i][right];
        }
        right--;
        if(right < left)   break;

        for (int i = right; i >= left; i--) {
            res[idx++] = matrix[down][i];
        }
        down--;
        if(down < up)    break;
        
        for (int i = down; i >= up; i--) {
            res[idx++] = matrix[i][left];
        }
        left++;
        if(left > right) break;
    }
    return res;
}