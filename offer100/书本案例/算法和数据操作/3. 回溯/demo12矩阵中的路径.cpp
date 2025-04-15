#include <bits/stdc++.h>

using namespace std;



int dir[4][2] = {0,1,1,0,0,-1,-1,0};

bool found = false;

bool backtracking(vector<vector<char>>& matrix, string word, vector<vector<bool>> &visited, int x, int y, int idx)
{
    if(idx == word.size()){
        found = true;
        return found;
    }
        
    for (int i = 0; i < 4; i++)
    {
        int nextx = dir[i][0];
        int nexty = dir[i][1];
        if(nextx < 0 || nextx >= matrix.size() || nexty < 0 || nexty >= matrix[0].size())
            continue;
        if(matrix[nextx][nexty] == word[idx] && visited[nextx][nexty] == false)
        {
            visited[nextx][nexty] = true;
            backtracking(matrix, word, visited, nextx, nexty, idx + 1);
            // 回溯
            visited[nextx][nexty] = false;
        }
    }
}



bool hasPath(vector<vector<char>>& matrix, string word) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] == word[0])
            {
                visited[i][j] = true;
                backtracking(matrix, word, visited, i, j, 1);
                visited[i][j] = false;
                if(found){
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    return 0;
}