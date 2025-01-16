#include <bits/stdc++.h>

using namespace std;


string LeftRotateString(string str, int n) 
{
    if(str == "")
        return str;
    n = n % str.size();
    reverse(str.begin(), str.begin() + n);
    reverse(str.begin() + n, str.end());
    reverse(str.begin(), str.end());
    return str;
}



int main()
{
    string str = "aab";
    int n = 10;
    string res = LeftRotateString(str, n);
    cout << res << endl;
    return 0;
}