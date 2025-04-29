#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    int slow = 0;
    int fast = 0;
    while (fast < s.size())
    {
        if(s[fast] >= 'a' && s[fast] <= 'z' || s[fast] >= '0' && s[fast] <= '9') 
            s[slow++] = s[fast];
        else if(s[fast] >= 'A' && s[fast] <= 'Z')
            s[slow++] = s[fast] + 32;
        fast++;
    }
    int left = 0;
    int right = slow - 1;
    for (int i = 0; i < slow; i++) {
        cout << s[i];
    }
    cout << endl;
    
    while (left < right)
    {
        if(s[left] ==  s[right]) {
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