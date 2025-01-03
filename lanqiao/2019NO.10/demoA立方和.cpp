#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

// 判断是否含有2019 是返回 true，否则返回 false
bool judge(int n)
{
    while(n > 0)
    {
        int temp = n % 10;
        if(temp == 2 || temp == 0 || temp == 1 || temp == 9)
            return true;
        n /= 10;
    }
    return false;
}
// 4097482414389
// 注意这里要对 i * i 进行数据类型强转，不然就溢出了
int main()
{
    bool ret = false;
    ll sum1 = 0;   // 和
    ll sum2 = 0;   // 平方和
    ll sum3 = 0;   //立方和
    for(int i = 1; i <= 2019; i++)
    {   
        ret = judge(i);
        if(ret == false)
            continue;
        sum1 += i;
        sum2 += i * i;
        sum3 = sum3 + (ll)(i * i) * i;
    }
    cout << "sum1: " << sum1 << endl;
    cout << "sum2: " << sum2 << endl;
    cout << "sum3: " << sum3 << endl;
    return 0;
}