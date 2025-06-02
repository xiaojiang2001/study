#include <bits/stdc++.h>

using namespace std;

// 合并[left,left]与[mid+1, right]两个区间
void merge(int a[], int left, int mid, int right)
{   
    int *temp = (int*)malloc((right - left + 1) * sizeof(int));
    int idx = 0;
    int i = left;
    int j = mid + 1;
    // 选择较为小的那个
    while (i <= mid && j <= right) {
        if(a[i] < a[j]) temp[idx++] = a[i++];
        else            temp[idx++] = a[j++];
    }
    while (i <= mid) temp[idx++] = a[i++];
    while (j <= right) temp[idx++] = a[j++];

    idx = 0;
    for (int i = left; i <= right ; i++) {
        a[i] = temp[idx++];
    }
    delete temp;
}


void mergeSort(int a[], int left, int right)
{
    if(left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);        // 递归排序左区间
    mergeSort(a, mid + 1, right);   // 递归排序右区间
    merge(a, left, mid, right);     // 归并
}

int main()
{
    int a[] = {3,5,2,8,9,1,7};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n-1);
    for (int i = 0; i < 7;i++) {
        printf("%d ", a[i]);
    }
    return 0;
}