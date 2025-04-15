#include <bits/stdc++.h>

using namespace std;

int Fibonacci(int n) 
{
    if(n <= 2)
        return 1;
    long long fibN = 0;
    long long fibNmin = 0;
    long long fibNmax = 1;
    for (int i = 2; i <= n; i++)
    {
        fibN = fibNmin + fibNmax;
        fibNmin = fibNmax;
        fibNmax = fibN;
    }
    return fibN;
}