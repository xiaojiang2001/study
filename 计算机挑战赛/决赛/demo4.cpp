#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 存储每个指挥官的历史比赛记录
    vector<vector<int>> records(n);

    // 读取每个指挥官的历史比赛记录
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int defeated;
            cin >> defeated;
            records[i].push_back(defeated - 1);  // 转换为0-based索引
        }
    }

    // 使用集合来存储被击败过的指挥官
    vector<bool> defeated(n, false);

    // 遍历每个指挥官的历史记录
    for (int i = 0; i < n; ++i) {
        for (int defeated_by_i : records[i]) {
            defeated[defeated_by_i] = true;
        }
    }

    // 可能成为最终胜者的指挥官
    vector<int> possible_winners;
    for (int i = 0; i < n; ++i) {
        if (!defeated[i]) {
            possible_winners.push_back(i);
        }
    }

    // 检查是否有其他指挥官可能成为最终胜者
    for (int i = 0; i < n; ++i) {
        if (defeated[i]) {
            bool can_be_winner = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && !defeated[j] && find(records[j].begin(), records[j].end(), i) == records[j].end()) {
                    can_be_winner = false;
                    break;
                }
            }
            if (can_be_winner) {
                possible_winners.push_back(i);
            }
        }
    }

    // 去重并排序
    sort(possible_winners.begin(), possible_winners.end());
    possible_winners.erase(unique(possible_winners.begin(), possible_winners.end()), possible_winners.end());

    // 输出结果
    cout << possible_winners.size() << " ";
    for (int winner : possible_winners) {
        cout << winner + 1 << " ";  // 转换回1-based索引
    }
    cout << endl;

    return 0;
}