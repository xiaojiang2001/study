#include <bits/stdc++.h>

using namespace std;


void merge(vector<int>& array, int l, int mid, int r)
{
    int *temp = new int[r-l+1];
    int i = l;
    int j = mid + 1;
    int idx = 0;
    //每次比较两区间最小的数，将更小者放入temp
    while(i <= mid && j <= r)  
    {
        if(array[i] <= array[j])
            temp[idx++] = array[i++];
        else
            temp[idx++] = array[j++];
    }

    //一个区间放完后,另二区间剩金元素放到temp末尾即可
    while(i <= mid)
        temp[idx++] = array[i++];
    while(j <= r)
        temp[idx++] = array[j++];
    // 把数组覆盖为原数组
    for (int i = l, k = 0; i <= r; i++, k++)
        array[i] = temp[k];
    delete[] temp;
}

// 归并排序
void mergeSort(vector<int>& array, int l, int r)
{
    if(l < r)
    {
        int mid = (l+r) / 2;
        mergeSort(array, l ,mid);       // 归并排序左区间
        mergeSort(array, mid+1 ,r);     // 归并排序右区间
        merge(array, l, mid, r);        // 归并两个区间
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