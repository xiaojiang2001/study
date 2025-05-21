#include <bits/stdc++.h>

using namespace std;

string addStrings(string num1, string num2) {
    string res = "";
    int len1 = num1.size() - 1;
    int len2 = num2.size() - 1;
    int carry = 0;
    while (len1 >= 0 || len2 >= 0 || carry == 1)
    {
        int digital1 = len1 >= 0 ? num1[len1--] - '0' : 0;
        int digital2 = len2 >= 0 ? num2[len2--] - '0' : 0;
        int sum = digital1 + digital2 + carry;
        if(sum >= 10) {
            res =  to_string(sum % 10) + res;
            carry = 1;
        }
        else {
            res =  to_string(sum) + res;
            carry = 0;
        }
    }
    
    return res;
}

int main()
{
    string res = addStrings("11", "123"); 
    cout << res << endl;
    return 0;
}