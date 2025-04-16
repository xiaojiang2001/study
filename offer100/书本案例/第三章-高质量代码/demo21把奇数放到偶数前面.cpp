#include <bits/stdc++.h>

using namespace std;


void Reorder(int* array, int arrayLen, bool (*func)(int))
{
    int* pBegin = array;
    int* pEnd   = array + arrayLen - 1; 

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && !func(*pBegin)) {
            pBegin++;
        }
        while (pBegin < pEnd && func(*pEnd)) {
            pEnd--;
        }
        
        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }   
    }
}

bool isEvent(int n)
{
    return (n & 0x01) == 0;
}

// 奇数放到偶数后面
int* reOrderArray(int* array, int arrayLen, int* returnSize ) {

    if(arrayLen <= 1){
        *returnSize = arrayLen;
        return array;
    }

    Reorder(array, arrayLen, isEvent);


    *returnSize = arrayLen;
    return array;
}