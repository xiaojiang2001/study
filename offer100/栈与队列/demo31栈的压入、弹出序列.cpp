#include <bits/stdc++.h>

using namespace std;

bool IsPopOrder(vector<int>& pushV, vector<int>& popV) 
{
    queue<int> que;
    stack<int> st;
    // 弹出数组存入队列
    for (auto num : popV) {
        que.push(num);
    }
    for (int i = 0; i < pushV.size(); i++)
    {
        // 压栈数组进栈
        st.push(pushV[i]);
        // 相等 弹出
        while (!que.empty() && !st.empty() && st.top() == que.front())
        {   
            st.pop();
            que.pop();
        }
    }
    if(!que.empty())
        return false;
    return true;
}

int main()
{
    vector<int> pushV{1,2,3,4,5};
    vector<int> popV{4,5,3,2,1};
    bool ret = IsPopOrder(pushV, popV);
    cout << "ret:" << ret << endl;
    return 0;
}