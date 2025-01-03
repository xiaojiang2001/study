#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const double INF = 1e9;

struct Edge {
    int to;
    double loss;  // 能量损耗率
};

typedef pair<double, int> PDI;  // (累积损耗, 节点)

void dijkstra(int start, int end, const vector<vector<Edge>>& graph, vector<double>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[start] = 1.0;  // 初始能量为 1.0

    priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
    pq.push({1.0, start});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            double new_loss = d * (1.0 - edge.loss / 100.0);

            if (new_loss > dist[v]) {
                dist[v] = new_loss;
                pq.push({new_loss, v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        double z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }

    int A, B;
    cin >> A >> B;

    vector<double> dist;
    dijkstra(A, B, graph, dist);

    if (dist[B] == INF) {
        cout << "No path found" << endl;
        return 0;
    }

    // 计算探测器 A 需要提供的能量
    double required_energy = 100.0 / dist[B];

    cout << fixed << setprecision(5) << required_energy << endl;

    return 0;
}