#include <bits/stdc++.h>

using namespace std;

// 这是
int getIdxAsVal(vector<int>& vec)
{
    if(vec.empty())
        return -1;
    
    int left = 0;
    int right = vec.size() - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if(mid == vec[mid])
            return mid;
        //不相等
        else if(vec[mid] < mid)
            left = mid + 1; 
        else
            right = mid - 1;
    }
    return -1;
}




int main()
{
    return 0;
}