#include <bits/stdc++.h>

using namespace std;

bool matchFunc(const char *str, const char *match)
{
    if(str == nullptr || match == nullptr)
        return false;
    
    int lenStr = strlen(str);
    int lenMatch = strlen(match);

    int hash[26] = {0};
    for (int i = 0; i < lenStr; i++){
        hash[str[i] - 'a']++;
    }

    int cnt = 0;
    for (int i = 0; i < lenMatch; i++)
    {
        if(match[i] == '.') cnt++;
        else if(i > 0 && match[i] == '*')    hash[match[i-1] - 'a'] = 0;
        else    hash[match[i] - 'a']--;
    }
    
    int hashSum = 0;
    for (int i = 0; i < 26; i++) 
    {
        if(hash[i] < 0) return false;
        else if(hash[i] > 0)
            hashSum += hash[i];
    }
    
    cout << "hashSum: " << hashSum << endl;
    cout << "cnt: " << cnt << endl;

    if(hashSum == cnt)
        return true;
    
    return false;
}

int main()
{
    const char *str = "aaa";
    const char *match = "aa.a";

    bool ret =  matchFunc(str,  match);
    cout << ret << endl;
}