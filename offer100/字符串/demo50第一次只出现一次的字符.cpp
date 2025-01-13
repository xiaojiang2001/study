#include <bits/stdc++.h>

using namespace std;

int FirstNotRepeatingChar(string str) 
{
    int hash[52] = {0};
    unordered_map<char,int> umap;   // 统计每个字符的位置


    for (int i = 0; i < str.size(); i++) 
    {
        // 记录位置
        umap[str[i]] = i;
        // 统计频率
        if(str[i] >= 'a' && str[i] <= 'z')
            hash[str[i] - 'a']++;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            hash[str[i] - 'A' + 26]++;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z' &&  hash[str[i] - 'a'] == 1){
            //cout << str[i] << " : " << hash[str[i] - 'a'] << endl;
            return umap[str[i]];
        }
           
        else if(str[i] >= 'A' && str[i] <= 'Z' && hash[str[i] - 'A' + 26] == 1){
            //cout << str[i] << " : " << hash[str[i] - 'A' + 26] << endl;
            return umap[str[i]];
        } 
    }

    return -1;
}

int main()
{
    string str = "tFinYsBvtwekLsVSeNaFkOsAqnQmqMqskOWgdPLMQaaotHiHcKesOGUxXHXndMTN";
    int res = FirstNotRepeatingChar(str); 
    cout << "res:" << res << endl;
    return 0;
}