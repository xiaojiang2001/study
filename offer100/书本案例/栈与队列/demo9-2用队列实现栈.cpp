#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void push(int node) {
        que1.push(node);
    }

    int pop() {
        int size = que1.size();
        size--;
        while (size--) {
            que1.push(que1.front());
            que1.pop();
        }
        int ret = que1.front();
        que1.pop();
        return ret;        
    }
    int top() {
        return que1.back();
    }
private:
    queue<int> que1;
};



int main()
{
    return 0;    
}