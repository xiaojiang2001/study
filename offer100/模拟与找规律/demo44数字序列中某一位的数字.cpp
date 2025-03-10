#include <bits/stdc++.h>

using namespace std;

int findNthDigit(int n)     // n = 1000
{
    int bits = 1;   // 位数
    int cnt = 9;    // 每个区间的数字个数   9 90 900
    while (n >= bits * cnt)
    {
        n = n - bits * cnt; 
        bits++;
        cnt = cnt * 10;
    }
    // 确定范围 
    int start = cnt / 10;           // 范围起始数字
    int num = start + (n-1) / bits; // 范围内的具体数字
    int idx =  (n-1) % bits + 1;    // 确定在某个数字的第idx位置
    int res = (num - pow(10, bits - idx)) % 10;
}

int main()
{
    for (int i = 0; i <= 55; i++)
        findNthDigit(i);
    return 0;
} 