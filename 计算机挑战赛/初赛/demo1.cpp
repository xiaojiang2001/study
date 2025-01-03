#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    // 每个学生至少获得一本书
    vector<int> books(n, 1); 

    // 右孩子比左孩子大
    for(int i = 0; i < scores.size() - 1; i++)
    {
        if(scores[i] < scores[i+1])
            books[i+1] = books[i] + 1;
    }
    
    // 左孩子比右孩子大
    for(int i = scores.size() - 1; i > 0; i--)
    {
        if(scores[i-1] > scores[i])
            books[i-1] = max(books[i-1], books[i] + 1);
    }

    // 计算总书籍数量
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += books[i];
    }
    
    cout << sum << endl;
    return 0;
}