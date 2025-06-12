#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void push(int value) {
        st1.push(value);
        if(st2.empty() || value < st2.top())
            st2.push(value);
        else
            st2.push(st2.top());
    }
    void pop() {
        st1.pop();
        st2.pop();
    }
    int top() {
        return st1.top();
    }
    int min() {
        return st2.top();
    }
private:
    stack<int> st1;     // 主栈
    stack<int> st2;     // 保存最小元素的栈 不仅要保存当前的，还要保存之前的
};

int main()
{
    return 0;
}
