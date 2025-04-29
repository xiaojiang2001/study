#include <bits/stdc++.h>

using namespace std;

string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result = "";
    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0)? (a[i] - '0') : 0;
        int digit2 = (j >= 0)? (b[j] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 2;
        result = char(sum % 2 + '0') + result;
        i--;
        j--;
    }
    return result;
}