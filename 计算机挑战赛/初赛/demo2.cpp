#include <iostream>  
#include <vector>  

using namespace std;  

struct Edge {  
    int to;  
    int time;  
};  

vector<Edge> graph[1000]; // 假设最多有1000个节点  
int res = 0;    // 去的时间结果集
int cnt = 0;    // 记录到达终点次数
void dfs(int node, int current_time, int target) {  
    // 到达终点了
    if (node == target) {  
        res += current_time; // 到达目标节点，累加时间
        cnt += 1;  // 到达终点
        return;  
    }  
    
    // 遍历所有邻接的边  
    for (auto &edge : graph[node]) {  
        dfs(edge.to, current_time + edge.time, target); // 递归访问  
    }  
}  

int main() {  
    int n, m, s, t, t0;  
    cin >> n >> m >> s >> t >> t0;  

    // 读取边的信息  
    for (int i = 0; i < m; i++) {  
        int x, y, time;  
        cin >> x >> y >> time;  
        graph[x].push_back({y, time}); // 添加边  
    }  

    // 从起点 s 开始 DFS，计算到达终点 t 的所有路径的时间  
    dfs(s, 0, t);  

    // 输出总游览时间，加上从东端返回西端的时间 t0 * cnt - 1
    res += t0*(cnt-1) ;
    cout << res << endl;  

    return 0;  
}
