#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //Insert one char from stringstream
    void Insert(char ch) {
        str += ch;
        mp[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (int i = 0; i < str.size(); i++) {
            if (mp[str[i]] == 1)
                return str[i];
        }
        return '#';
    }

  private:
    string str;                     // 用于拼接的字符串
    unordered_map<char, int> mp;    // 统计每个字符串出现的次数
};



int main()
{

}