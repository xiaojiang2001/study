#include <bits/stdc++.h>

using namespace std;

// void insertSort(int a[], int n)
// {
//     for (size_t i = 1; i <= n; i++)
//     {
//         if(a[i] < a[i-1])
//         {
//             int j = i - 1;
//             int temp = a[i];
//             do {
//                 a[j+1] = a[j];
//                 j--;
//             } while (j >= 0 && temp < a[j]);
//             a[j+1] = temp;
//         }
//     }
// } 


void insertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
        {
            int temp = a[i];
            int j = i;
            do
            {
                a[j] = a[j - 1];
                j--;
            } while (j >= 0 && temp < a[j]);
            a[j + 1] = temp;
        }
    }
}

int main()
{
    int a[] = {3,5,2,8,9,1,7};
    int n = sizeof(a) / sizeof(a[0]);
    insertSort(a, n);
    for (int i = 0; i < 7;i++) {
        printf("%d ", a[i]);
    }
    return 0;
}