#include <bits/stdc++.h>

using namespace std;

int MissingNumber(vector<int>& vec)
{
    if(vec.empty())
        return -1;

    int left = 0;
    int right = vec.size() - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if(vec[mid] != mid)
        {
            if((mid == 0 ) || (vec[mid-1] = mid - 1))
                return mid;
            else
                right = mid -1;
        }
        else
            left = mid + 1;
    }
    
    return -1;
}




int main()
{
    return 0;
}