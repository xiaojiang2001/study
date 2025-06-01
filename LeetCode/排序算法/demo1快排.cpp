#include <bits/stdc++.h>

using namespace std;    

int partition(vector<int> &array, int left, int right)
{
    int pivot = (left + right) / 2;
    swap(array[pivot], array[right]);

    int idx = left;
    for (int i = left; i < right; i++)
    {
        if(array[i] < array[right]) {
            swap(array[i], array[idx]);
            idx++;
        }
    }
    swap(array[right], array[idx]);
    return idx;
}

void quickSort(vector<int> &array, int left, int right)
{
    if(left >= right)
        return;

    int pivot = partition(array, left, right);
    quickSort(array, left, pivot - 1);
    quickSort(array, pivot + 1, right);
}

int quickSelect(vector<int> &array, int left, int right, int k)
{
    if(k < left || k > right || left > right)
        return -1;

    if(left == right)
        return array[left];
    int pivot = partition(array, left, right);
    if(pivot == k)
        return array[k];
    else if(pivot < k)
        return quickSelect(array, pivot + 1, right, k);
    else 
        return quickSelect(array, left, pivot - 1, k);
}

int main()
{
   vector<int> a{16,20,23,27,45,56,89,54,76,82};
//    quickSort(a, 0 ,9);
//    for (int i = 0; i < 10; i++){
//       printf("%d ", a[i]);
//    }
//    printf("\n");

    // 快速选择
    int k;
    k = 11;
    int ret = quickSelect(a, 0 , 9, k-1);
    cout << ret;
   return 0;
}