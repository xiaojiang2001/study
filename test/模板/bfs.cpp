#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};      // 表示四个方向

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    queue<pair<int, int>> que;
    que.push({x, y});
    // 注意 加入队列后就要立刻标记访问
    visited[x][y] = true;
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second; 			// 当前节点坐标
        for (int i = 0; i < 4; i++)
        {
            int nextx = cur.first + dir[i][0];
            int nexty = cur.second + dir[i][1];
            if(nextx < 0 || nexty < 0 || nextx > grid.size() || nexty > grid[0].size())
                continue;
            if(!visited[nextx][nexty] && grid[nextx][nexty] == 1)
            {
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
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
                bfs(grid, visited, i, j);   // 进入递归
                // 其他逻辑
            }
        }
        
    }
}