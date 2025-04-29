#include <bits/stdc++.h>

using namespace std;



bool vowel(char ch)
{
    if( ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' ||
        ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
        return true;
    return false;
}

string reverseVowels(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        // 找到左边的第一个元音字母
        while (i < j && !vowel(s[i])) {
            i++;
        }
        // 找到右边第一个元音字母
        while (i < j && !vowel(s[j])) {
            j--;
        }
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}


int main()
{

}