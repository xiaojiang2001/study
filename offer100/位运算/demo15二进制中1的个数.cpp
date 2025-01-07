#include <bits/stdc++.h>

using namespace std;

int NumberOf1(int n) 
{
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        if((n & (1 << i)) != 0)
            res++;
    }
    return res;
}


int main()
{
    int n;
    cin >> n;
    int res = NumberOf1(n);
    cout << res << endl;
    return 0;
}