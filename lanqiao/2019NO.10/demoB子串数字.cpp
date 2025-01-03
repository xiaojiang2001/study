#include <bits/stdc++.h>

using namespace std;


int ctoi(char ch)
{
    return ch - 'A' + 1;
}

// ans: 3725573269
int main()
{
    string str = "LANQIAO";
    long long res = 0;
    // 26进制
    for(auto ch : str)
    {
        res = res * 26;
        res += ctoi(ch);
    }
    cout << res << endl;
    return 0;
}