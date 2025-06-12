#include <bits/stdc++.h>

using namespace std;

bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
{
    stack<int> st;
    int idx = 0;
    // 模拟压入栈
    for (int i = 0; i < pushV.size(); i++)
    {
        st.push(pushV[i]);
        while (!st.empty() && st.top() == popV[idx]) {
            st.pop();
            idx++;
        }
    }

    if(st.empty() && idx == popV.size())
        return true;
    
    return false;
}


int main()
{
    return 0;
}