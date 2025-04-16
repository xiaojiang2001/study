#include <bits/stdc++.h>

bool equal(double base, double data)
{
    if(abs(base - data) < 1e-9)
        return true;
    return false;
}

double Power(double base, int exponent) 
{
    bool inValid = false;
    if(equal(base, 0) && exponent <= 0){
        inValid = true;
        return 0.0;
    }

    unsigned int absExpoent = abs(exponent);
    double sum = 1.0; 
    for (int i = 0; i < absExpoent; i++) {
        sum *= base;
    }
    if(exponent < 0)
        return 1.0 / sum;
    return sum;
}