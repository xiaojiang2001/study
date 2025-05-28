#include <bits/stdc++.h>


using namespace std;

int findLUSlength(vector<string>& strs)
{
    int res = -1;
    string longStr;

    // 获取最长字符串及长度
    for(auto str : strs)
    {
       if(str.size() > res) { 
            res = str.size();
            longStr = str;
       }
    }

    for (auto str : strs)
    {
        
    }
    

}