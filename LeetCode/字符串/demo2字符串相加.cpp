#include <bits/stdc++.h>

using namespace std;

string addStrings(string num1, string num2) {
    int s1 = num1.size() - 1;
    int s2 = num2.size() - 1;

    string result = "";

    // 保证num1 > num2
    int carry = 0;
    while (s1 >= 0 || s2 >= 0 || carry)
    {
        int digit1 = (s1 >= 0)? (num1[s1] - '0') : 0;
        int digit2 = (s2 >= 0)? (num2[s2] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = char((sum % 10) + '0') + result;
        s1--;
        s2--;
    }
    
    return result;
}

int main()
{

}