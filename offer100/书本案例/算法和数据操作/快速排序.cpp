#include <bits/stdc++.h>

using namespace std;


int partition(vector<int>& array, int left, int right)
{
    if(array.empty() || left < 0 || right >= array.size())
        return -1;

    int pivot = rand() % (right - left + 1) + 1;
    int pivotVal = array[pivot];

    swap(array[pivot], array[right]);

    int idx = left;
    for (int i = left; i < right; i++)
    {
        if(array[i] < pivotVal) {
            swap(array[i], array[idx]);
            idx++;
        }
    }
    
    swap(array[idx], array[right]);
    return idx;
} 
