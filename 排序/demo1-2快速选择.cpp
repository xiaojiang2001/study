#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& array, int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int pival = array[pivotIndex];
    swap(array[pivotIndex], array[right]);

    int idx = left;
    for (int i = left; i < right; i++)
    {
        if(array[i] < pival) {
            swap(array[i], array[idx]);
            idx++;
        }
    }
    swap(array[right], array[idx]);
    return idx;
}


// 计算奇数个数组成的数组的中位数
int quickFind(vector<int> &array, int left, int right, int k)
{
    if(left == right)   return array[left];
    int pivotIndex = partition(array, left, right);
    if(pivotIndex == k)
        return array[pivotIndex];
    else if(pivotIndex < k)
        quickFind(array, left, pivotIndex - 1, k);
    else
        quickFind(array, pivotIndex + 1, right, k);
}

// 计算一个子数组是否满足条件
bool subArray(vector<int>& array)
{
    if (array.size() < 1 || array.size() % 2 == 0)
        return false;
    // 一定是奇个数
    int midVal = quickFind(array, 0, array.size() -1 , array.size() / 2);     
    int midIdx = array.size() / 2 + 1;  // 中间位置
    if (array[midIdx] == midVal)
        return true;
    return false;
}

int countArrayRes(vector<int>& array)
{
    int res = 0;
    bool flag = false;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i; j < array.size(); i++)
        {
            vector<int> subArray(array.begin() + i, array.begin() + j + 1);
            flag = countArrayRes(subArray);
            if(subArray.size() % 2 == 1 && flag) {
                res++;
                flag = false;
            }
        }
    }
    
}

int main()
{

    return 0;
}