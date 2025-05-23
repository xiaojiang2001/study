#include <bits/stdc++.h>

using namespace std;

bool detectCapitalUse(string word) 
{
    if(word.size() == 1)
        return true;
    bool flag1 = isupper(word[0])? true : false;
    bool flag2 = isupper(word[1])? true : false;
    if(flag1 == false && flag2 == true)
        return false;
    for (int i = 2; i < word.size(); i++)
    {
        // 全部大写
        if(flag1 == true && flag2 == true) {
            if(islower(word[i]))   
                return false;
        }
        // 全部小写
        else if(flag1 == false && flag2 == false) {
            if(isupper(word[i]))   
                return false;
        }
        // 大写开头，后面小写
        else if(flag1 == true && flag2 == false) {
            if(isupper(word[i]))   
                return false;
        }  
    }
    return true;
}