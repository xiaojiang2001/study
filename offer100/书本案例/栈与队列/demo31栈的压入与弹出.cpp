#include <bits/stdc++.h>

using namespace std;

bool IsPopOrder(vector<int>& pushV, vector<int>& popV) 
{
    stack<int> st;  // 辅助栈，把pushV模拟压入栈
    int p1 = 0;     // 指向 pushV 的指针
    int p2 = 0;     // 指向 popV 的指针

    while (p1 < pushV.size())
    {
        st.push(pushV[p1++]);
        while (!st.empty() && st.top() == popV[p2]) {
            st.pop();
            p2++;
        }
    }
    if(st.empty() && p2 == popV.size())
        return true;   
    
    return false;
}

int main()
{
    return 0;
}