#include <bits/stdc++.h>

using namespace std;

void insertSort(int a[], int n)
{
    for (size_t i = 1; i <= n; i++)
    {
        if(a[i] < a[i-1])
        {
            int j = i - 1;
            int temp = a[i];
            do {
                a[j+1] = a[j];
                j--;
            } while (j >= 0 && temp < a[j]);
            a[j+1] = temp;
        }
    }
} 

int main()
{
    int a[] = {1,4,7,9,10,5,8};
    insertSort(a, 7);
    for (int i = 0; i < 7;i++) {
        printf("%d ", a[i]);
    }
    return 0;
}