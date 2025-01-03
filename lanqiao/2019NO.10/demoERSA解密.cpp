#include <bits/stdc++.h>

using namespace std;

// 生成2个质数 p、q
/*
n = p * q
d 与 (p-1) * (q-1) 互质
(d * e) % (p-1)*(q-1) = 1
n d e 私钥
n d   公钥
*/
typedef long long ll;

// 判断2个数是否有公因子
bool judge(ll x, ll y)
{
    // 保证 x <= y
    if(x > y)   swap(x, y);
    for (ll i = 2; i <= x; i++)
    {
        if(x % i == 0 && y % 2 ==0)
            return false;
    }
    return true;
}
// 不妨通过前面2个条件，暴力求解p、q
// p: 891234941
// q: 1123984201
// p: 1123984201
// q: 891234941
int main()
{
    ll n = 1001733993063167141;
    int d = 212353;
    int C = 20190324;
    ll p, q;
    // 开始查询满足条件的 p、q
    // p * q =  1001733993063167141;
    // (p-1) * (q-1) 与 d 互斥
    for (ll p = 2; p < n; p++)
    {
        // p不是n的因数
        if(n % p != 0)
            continue;
        q = n / p;
        int temp = (p-1) * (q-1);
        if(judge(temp, d))
        {
            cout << "p: " << p << endl;
            cout << "q: " << q << endl;
            break;
        }
    }

    // 找到 p、q 求解e
    ll e = 0;
    __uint128_t temp;
    for(ll k = 1; k < LLONG_MAX; k++)
    {
        int temp = k * (p-1) * (q-1) + 1;
        if(temp % d == 0)
        {
            cout << "temp: " << temp << endl; 
            e = temp / d;
            break;
        }
    }
    cout << "e: " << e << endl;
    // // 求解X
    // int X = 1;
    // // 计算pow(C,e) 一旦超过n就减去n 不然太大了
    // for (ll i = 0; i < e; i++)
    // {
    //     X = X * C;
    //     if(X >= n)
    //         X -= n;
    // }

    // X = X % n;
    // cout << "X: " << X;
    return 0;
}