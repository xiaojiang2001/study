#include <bits/stdc++.h>

using namespace std;

int findSpecialInteger(vector<int>& arr) {
    int len = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == arr[i + len / 4])
            return arr[i];
    }
    return -1;
}