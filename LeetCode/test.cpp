#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example usage of the C++14 features
    auto lambda = [](int x) { return x * x; };
    cout << "Square of 5: " << lambda(5) << endl;

    // Using a structured binding (C++17 feature, but works in C++14 with some compilers)
    pair<int, int> p = {1, 2};
    auto [a, b] = p;
    cout << "Pair values: " << a << ", " << b << endl;

    return 0;
}