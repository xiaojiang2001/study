#include <bits/stdc++.h>

using namespace std;


int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];

        if(nextx < 0 || nexty < 0 || nextx > grid.size() || nexty > grid[0].size())
            continue;

        if(!visited[nextx][nexty] && grid[nextx][nexty])
        {
            // 业务逻辑操作

            visited[nextx][nexty] = true;
            dfs(grid, visited, nextx, nexty);
        }
    }
    
}




int main()
{
    int n, m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; i < grid[0].size(); i++)
        {
            // 找到一块未访问过的陆地
            if(visited[i][j] == false && grid[i][j])
            {
                visited[i][j] = true;
                dfs(grid, visited, i, j);   // 进入递归
                // 其他逻辑
            }
        }
        
    }
    
    return 0;
}