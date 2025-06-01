#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if(array[j] > array[j+1])
                swap(array[j], array[j+1]);
        }
    }
}

int main()
{ 
    int a[] = {1,4,7,9,10,5,8};
    int len = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

