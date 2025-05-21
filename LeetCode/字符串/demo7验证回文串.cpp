#include <bits/stdc++.h>

using namespace std;


//s = "A man, a plan, a canal: Panama
bool isPalindrome(string s) {
    int slow = 0;
    int fast = 0;
    // 清理字符串
    for (int fast = 0; fast < s.size(); fast++) {
        if(isupper(s[fast])){
            s[fast] = s[fast] + 32;
            s[slow++] = s[fast];
        }   
        else if(islower(s[fast]) || isdigit(s[fast])) {
            s[slow++] = s[fast];
        }
    }

    int left = 0;
    int right = slow - 1;
    while (left <= right)
    {
        if(s[left] == s[right]) {
            left++;
            right--;
        }
        else    
            return false;
    }
    return true;
}

int main()
{
    string str = "0P";
    bool ret = isPalindrome(str);
    cout << "ret: " << ret << endl;
    return 0;
}