#include <bits/stdc++.h>

using namespace std;

int findNthDigit(int n) 
{
    string s = "0123456789101112131415161718192021222324252627282930313233343536373839404142";
    cout << "n=" << n << "  " << s[n] << endl;
    return 0;
}

int main()
{
    for (int i = 0; i <= 55; i++)
        findNthDigit(i);
    return 0;
} 