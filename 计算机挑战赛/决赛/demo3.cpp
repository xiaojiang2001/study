#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// 检查一个字符串是否是另一个字符串的前缀
bool isPrefix(const string& s1, const string& s2) {
    if (s1.length() > s2.length()) return false;
    return s2.substr(0, s1.length()) == s1;
}

// 检查一个子集是否是安全的
bool isSafeSubset(const vector<string>& subset) {
    for (size_t i = 0; i < subset.size(); ++i) {
        for (size_t j = 0; j < subset.size(); ++j) {
            if (i != j && isPrefix(subset[i], subset[j])) {
                return false;
            }
        }
    }
    return true;
}

// 计算所有安全子集的数量
long long countSafeSubsets(const vector<string>& codes) {
    int n = codes.size();
    long long safeCount = 0;

    // 生成所有子集
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<string> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(codes[i]);
            }
        }
        if (isSafeSubset(subset)) {
            safeCount++;
        }
    }

    return safeCount;
}

int main() {
    int n;
    cin >> n;

    vector<string> codes(n);
    for (int i = 0; i < n; ++i) {
        cin >> codes[i];
    }

    long long safeSubsets = countSafeSubsets(codes);
    cout << safeSubsets << endl;

    return 0;
}