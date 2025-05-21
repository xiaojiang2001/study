#include <bits/stdc++.h>

using namespace std;

string addBinary(string a, string b) {
    string res = "";
    int idx1 = a.size() - 1;
    int idx2 = b.size() - 1;
    int carry = 0;
    while (idx1 >= 0 || idx2 >= 0 || carry == 1)
    {
        int digital1 = idx1 >= 0? a[idx1--] - '0' : 0;
        int digital2 = idx2 >= 0? b[idx2--] - '0' : 0;
        int sum = digital1 + digital2 + carry;
        carry = sum / 2;
        res = to_string(sum % 2) + res;
    }
    return res;
}