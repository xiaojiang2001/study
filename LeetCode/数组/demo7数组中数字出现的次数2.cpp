#include <bits/stdc++.h>

using namespace std;

int trainingPlan(vector<int>& actions) 
{
    int res = 0;
    unsigned int bitMask = 1 << 31;     // 检查每一位是否为1
    for (int i = 0; i < 32; i++)
    {
        int bitSum = 0;                  // 用于统计当前位为1的数字的个数
        for (auto num : actions) {
            if(num & bitMask)
                bitSum++;
        }
        // 将当前位的统计结果（模3）拼接到结果中
        res = (res << 1) +  bitSum % 3;
        bitMask >>= 1;
    }
    return res;
}