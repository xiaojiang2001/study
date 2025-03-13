#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int findNthDigit(int n) {   // n = 1000
    if(n == 0)
        return 0;
    // 位数
    int bits = 1;   
    // 记录当前位数区间的起始数字：1,10,100...
    long long start = 1;
        // 记录当前区间之前总共有多少位数字
    long long cnt = 9;   
    while (n > cnt) {
        n = n - cnt;
        start *= 10;
        bits++;
        //该区间的总共位数
        cnt = 9 * start * bits;
    }
    int num = start + (n - 1) / bits;   // 范围内的具体数字
    int idx =  (n - 1) % bits;          // 确定在某个数字的第idx位置
    int res = to_string(num)[idx] - '0';
    return res;
}

// 0 1 2 3 4 5 6 7 8 9 1 0 1 1 1 2 1 3 
int main()
{
    int n = 11;
    int ret = findNthDigit(n);
    cout << ret << endl;
    return 0;
} 