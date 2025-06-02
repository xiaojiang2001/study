#include <bits/stdc++.h>

using namespace std;

void shellSort(int a[], int n)
{
    // 遍历增量
    for (int gap = n >> 1; gap >= 1; gap >>= 1)
    {
        for (int i = gap; i < n; i++)
        {
            if(a[i] < a[i-1])
            {
                int temp = a[i];
                int j = i - gap;
                do
                {
                    a[j+1] = a[j];
                    j -= gap;
                } while (j >= 0 && a[j] > temp);
                a[j+gap] = temp;
            }
        } 
    }
}