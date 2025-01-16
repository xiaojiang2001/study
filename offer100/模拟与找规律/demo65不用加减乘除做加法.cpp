#include <bits/stdc++.h>

using namespace std;

int Add(int num1, int num2) 
{
    while (num2 != 0) {
        int c = (num1 & num2) << 1; // 进位数
        num1 = num1 ^ num2;         // 无进位和
        num2 = c;                   
    }
    return num1;
}

int main()
{

    return 0;
}