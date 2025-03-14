#include <bits/stdc++.h>

using namespace std;

double Power(double base, int exponent) {
    if(exponent == 0)
        return 1;
    if(base == 0.000000)
        return 0;

    double res = 1.0;
    for (int i = 0; i < abs(exponent); i++) {
        res *= base;
    }
    if(exponent < 0)
        res = 1.0 / res;
    return res;
}

int main()
{

}