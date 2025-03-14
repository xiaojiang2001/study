#include <bits/stdc++.h>

using namespace std;


// 获取0-99的位数和
int getSum(int x)
{
    if(x == 100)
        return 1;
    return x % 10 + x / 10;
}
// 判断是否邻接
bool judge(vector<vector<bool>> &visited, int rows, int cols)
{
    if(rows >= visited.size() || cols >= visited[0].size())
        return false;
    if(rows == 0 && cols == 0)
        return true;
    // 第一行
    if(rows == 0){
        if(visited[0][cols-1])
            return true;
        else
            return false;
    }
    // 第一列
    if(cols == 0){
        if(visited[rows-1][0])
            return true;
        else
            return false;
    }

    //其他
    if(visited[rows-1][cols] || visited[rows][cols-1])
        return true;

    return false;
}


int movingCount(int threshold, int rows, int cols) {
    int sum  = 0;
    int result = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[0][0] = true;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum = getSum(i) + getSum(j);
            bool ret = judge(visited, i, j);
            if(sum > threshold || ret == false)
                continue;
            result++;
            visited[i][j] = true;
        }
    }
    return result;
}



int main()
{
    movingCount(10,1,100);
    return 0;
}