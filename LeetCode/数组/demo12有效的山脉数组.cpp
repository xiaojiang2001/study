#include <bits/stdc++.h>

using namespace std;

// 模拟
bool validMountainArray(vector<int>& arr) 
{
    if(arr.size() < 3)
        return false;

    int i = 0;
    while (i < arr.size() - 1)
    {
        if(arr[i] < arr[i+1])       // 递增
            i++;
        else if(arr[i] == arr[i+1])  // 水平
            return false;
        else                        // 遇到峰值
            break;  
    }
    // 单调
    if(i == 0 || i == arr.size() - 1)   
        return false;

    // 开始递减
    while (i < arr.size() - 1)
    {
        if(arr[i] > arr[i+1])       // 递减
            i++;
        else if(arr[i] == arr[i+1])  // 水平
            return false;
        else                        // 遇到衰减
            break;  
    }

    if(i == arr.size() - 1)
        return true;
    return false;
}

// 2. 找到数组中最大数字的下标，左边是递增的，右边是递减的