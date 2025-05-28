#include <bits/stdc++.h>

using namespace std;


// 以第一个字母为基准，逐个扫描后续单词的每个字母
string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    bool quit = false;
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (auto str : strs)
        {
            if(i >= str.size() || str[i] != strs[0][i])    
                quit = true;
        }
        if(quit)
            break;
        res += strs[0][i];
    }

    return res;
}



int main()
{

}