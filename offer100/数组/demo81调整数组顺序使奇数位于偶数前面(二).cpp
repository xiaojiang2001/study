#include <bits/stdc++.h>

using namespace std;

vector<int> reOrderArrayTwo(vector<int>& array) 
{
    int i = 0;
    int j = array.size() - 1;
    while (i < j)
    {
        // 奇奇
        if(array[i] % 2 == 1 && array[j] % 2 == 1)
            i++;
        // 偶偶
        if(array[i] % 2 == 0 && array[j] % 2 == 0)
            j--;
        // 奇偶
        if(array[i] % 2 == 1 && array[j] % 2 == 0){
            i++;
            j--;
        }
        // 偶奇
        if(array[i] % 2 == 0 && array[j] % 2 == 1){
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    return array;
}

int main()
{

    return 0;
}