#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void push(int value) {
        st.push(value);
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        int minVal = st.top();
        stack<int> st2;
        while (!st.empty())
        {
            if(st.top() < minVal)
                minVal = st.top();
            st2.push(st.top());
            st.pop();
        }
        
        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }

        return minVal;
    }
private:
    stack<int> st;
};

int main()
{
    Solution s;
    return 0;
}