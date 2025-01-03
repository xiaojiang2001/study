#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <climits>  

using namespace std;  

int main() {  
    int L; // 植物园的长度  
    cin >> L;  

    int S, T, M; // 步长范围和障碍物数量  
    cin >> S >> T >> M;  

    vector<int> obstacles(M);  
    for (int i = 0; i < M; ++i) 
    {  
        cin >> obstacles[i]; // 输入障碍物位置  
    }  

    // 创建用于记录已知障碍物的集合  
    vector<bool> isObstacle(L + 1, false);  
    for (int obstacle : obstacles) 
    {  
        isObstacle[obstacle] = true;    // 标记障碍物位置  
    }  

    vector<int> dp(L + 1, INT_MAX);     // dp数组，初始化为无穷大  
    dp[0] = 0;                          // 开始位置踩到的障碍物数  

    // 动规遍历  
    for (int i = 0; i < L; ++i) 
    {  
        if (dp[i] == INT_MAX) 
            continue;                   // 如果无法到达i，则跳过  
        for (int d = S; d <= T; ++d) 
        {  
            int j = i + d; // 新位置  
            if (j > L) 
                break; // 超出范围  
            // 计算新位置踩到的障碍物数  
            int additionalObstacles = isObstacle[j] ? 1 : 0;  
            dp[j] = min(dp[j], dp[i] + additionalObstacles);  
        }  
    }  

    // 找到到达L及以上位置的最小障碍物数量  
    int result = INT_MAX;  
    for (int i = L; i <= L; ++i)
    {  
        result = min(result, dp[i]);  
    }  

    // 输出结果  
    cout << result << endl;  

    return 0;  
}