#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> father;

// 并查集初始化
void init(const vector<string>& names) {
    for (const string& name : names) {
        father[name] = name;
    }
}

// 并查集里寻根的过程
string find(const string& u) {
    return father[u] == u ? u : father[u] = find(father[u]); // 路径压缩
}

// 判断 u 和 v 是否找到同一个根
bool isSame(const string& u, const string& v) {
    return find(u) == find(v);
}

// 将 v -> u 这条边加入并查集
void join(const string& u, const string& v) {
    string rootU = find(u); // 寻找 u 的根
    string rootV = find(v); // 寻找 v 的根
    if (rootU == rootV) return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[rootV] = rootU;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> names(N);
    for (int i = 0; i < N; ++i) {
        cin >> names[i];
    }
    // 初始化并查集
    init(names);

    for (int i = 0; i < M; ++i) {
        string a, b;
        cin >> a >> b;
        // 加入并查集
        join(a, b);
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        string a, b;
        cin >> a >> b;
        // 判断是否有联系
        if (isSame(a, b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}