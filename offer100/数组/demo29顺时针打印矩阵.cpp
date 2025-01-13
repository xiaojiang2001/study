#include <bits/stdc++.h>

using namespace std;
/*
{1,2,3,1},
{4,5,6,1},
{4,5,6,1}
*/
vector<int> printMatrix(vector<vector<int> > matrix) 
{
    int n = matrix.size();              // 行数
    int m = matrix[0].size();           // 列数
    vector<int> result(m * n);
    int idx = 0;            // 结果集下标
    int circle = 0;         // 圈数

    cout << "n: " << n << endl;
    cout << "m: " << m << endl;

    if(n == 1 && m ==1) {
        result[idx] = matrix[0][0];
        return result;
    }
    
    while(idx < m * n)
    {
        // 上面第一行
        for(int i = circle; i < m-1-circle; i++)
            result[idx++] = matrix[circle][i];
        
        // 右边列
        for(int j = circle; j < n-1-circle; j++) 
            result[idx++] = matrix[j][m-1-circle];


        // 最下面一行
        for(int i = m-1-circle; i >= 1+circle; i--)
            result[idx++] = matrix[n-1-circle][i];

        // 左边列
        for(int j = n-1-circle; j >= 1+circle; j--)
            result[idx++] = matrix[j][circle];
            
        circle++;
    }
    return result;
}

int main()
{
    vector<vector<int>> nums{{1,2,3,4,5}};

    vector<int> res = printMatrix(nums);

    for (auto num : res)
        cout << num << " ";
    
    cout << endl;

    return 0;
}