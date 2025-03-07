#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {1,0,0,1,-1,0,0,-1};
bool found = false;
void dfs(vector<vector<char>>& matrix, vector<vector<bool>>& visited, int x, int y, string word, int idx)
{
     // 如果已经匹配到字符串的最后一个字符，设置全局变量found为true
    if (idx == word.size()) {
        found = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        // 越界
        if(nextx < 0 || nextx >= matrix.size() || nexty < 0 || nexty >= matrix[0].size())
            continue;
        // 存在下一条通路
        if(visited[nextx][nexty] == false && matrix[nextx][nexty] == word[idx]) {
            visited[nextx][nexty] = true;
            dfs(matrix, visited, nextx, nexty, word, idx + 1);
            // 回溯
            visited[nextx][nexty] = false;
        }
    }
}
bool hasPath(vector<vector<char>>& matrix, string word) {
    int n = matrix.size();      // 行
    int m = matrix[0].size();   // 列
    if(n == 0)
        return false;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 找到起点
            if(matrix[i][j] == word[0]) {
                visited[i][j] = true;
                dfs(matrix, visited, i, j, word, 1);
                // 如果找到路径，直接返回true
                if (found) {
                    return true;
                }
                // 回溯
                visited[i][j] = false;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> mat{{'A','B','C'},
                             {'B','E','D'},
                             {'F','G','G'}
                             };
    string word = "ABCDEBF";
    bool ret = hasPath(mat, word);
    cout << "res:" << ret << endl;
    return 0;
}