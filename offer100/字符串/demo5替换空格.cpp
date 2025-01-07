#include <bits/stdc++.h>

using namespace std;

string replaceSpace(string s) 
{
    string res = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
            res += "%20";
        else
            res += s[i];
    }
    return res;
}


int main()
{
    string s = "We Are Happy";
    string ret = replaceSpace(s);
    cout << ret << endl;
    return 0;
}