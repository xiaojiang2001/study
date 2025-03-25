#include <bits/stdc++.h>

using namespace std;


void merge(vector<int>& array, int left, int mid, int right)
{
    int i = left;       // 左区间起点
    int j = mid + 1;    // 右区间起点
    int *temp = new int[right - left + 1];  // 开辟临时区间
    int idx = 0;        // 临时区间下标

    // 保存较小值
    while (i <= mid && j <= right)
    {
        if(array[i] <= array[j])
            temp[idx++] = array[i++];
        else
            temp[idx++] = array[j++];
    }
    
    // 一个区间结束，保存另一个区间
    while (i <= mid)
        temp[idx++] = array[i++];
    while (j <= right)
        temp[idx++] = array[j++];

    // 保存temp覆array
    for (int index = left, i = 0; index <= right; index++)
        array[index] = temp[i++];

    delete[] temp;         // 删除堆区内存
}


void mergeSort(vector<int>& array, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);        // 归并排序左区间
        mergeSort(array, mid + 1, right);   // 归并排序右区间
        merge(array, left, mid, right);     // 归并左右区间
    }
}


int main()
{
    vector<int> a{23,33,44,51,21,37,28,76,38,67,56};
    mergeSort(a, 0, 10);
    for(auto num: a)
        cout << num << " ";
    cout << endl;
    return 0;
}