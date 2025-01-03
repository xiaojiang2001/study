#include <bits/stdc++.h>

using namespace std;

// 判断一个数是否为质数
int judge(long long n)
{
    for(long long i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

// 17569
int main()
{
    vector<long long> res(2020, 0);
    int idx = 1;    // 从1开始存
    int ret = 0;
    for(long long i = 2; i <= LONG_LONG_MAX; i++)
    {
        ret = judge(i);
        // 非质数
        if(ret == 0)
            continue;
        // 质数
        res[idx++] = i;
        // 存满2019个数字
        if(idx == 2020)     // 存9个
            break;
    }
    for (int i = 1; i <= 2019; i++)
        cout << res[i] << " ";
    cout << endl;
    cout << res[2019];
    cout << endl;
    return 0;
}
