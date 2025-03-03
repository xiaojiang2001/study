#include <bits/stdc++.h>

using namespace std;
// 1 2 3
// 4 5 6
// 7 8 9

vector<int> printMatrix(vector<vector<int> > matrix) 
{
    // 空数组
    if(matrix.size() == 0)
        return  vector<int>{};
    int up = 0;                         // 上边界
    int down = matrix.size() - 1;       // 下边界
    int left = 0;                       // 左边界
    int right = matrix[0].size() - 1;   // 右边界
    vector<int> result;

    while(up <= down && left <= right)
    {
        // 上一行
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[up][i]);
        }
        up++;
        if(up > down)   break;

        // 右
        for (int i = up; i <= down; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        if(right < left)    break;

        // 下
        for (int i = right; i >= left; i--){
            result.push_back(matrix[down][i]);
        }
        down--;
        if(down < up)   break;
        

        // 左
        for (size_t i = down; i >= up; i--) {
            result.push_back(matrix[i][left]);
        }
        left++;
        if(left > right)    break;
    }
    return result;
}

int main()
{
    vector<vector<int>> nums{{1,2,3},{4,5,6},{7,8,9}};

    vector<int> res = printMatrix(nums);

    for (auto num : res)
        cout << num << " ";
    
    cout << endl;

    return 0;
}