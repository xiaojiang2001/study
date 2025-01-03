#include <bits/stdc++.h>

using namespace std;


int searchLeft(vector<int>& nums, int k)
{
    int left = 0;
    int right = nums.size() - 1;
    bool flag = false;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] < k)
            left = mid + 1;
        else if(nums[mid] > k)
            right = mid - 1;
        else {
            flag = true;
            right = mid - 1;
        }
    }
    if(flag)    
        return left;
    return -1;
}

int searchRight(vector<int>& nums, int k)
{
    int left = 0;
    int right = nums.size() - 1;
    bool flag = false;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] < k)
            left = mid + 1;
        else if(nums[mid] > k)
            right = mid - 1;
        else {
            flag = true;
            left = mid +  1;
        }
    }
    if(flag)    
        return right;
    return -1;
}


int GetNumberOfK(vector<int>& nums, int k) 
{
    int leftIdx  = searchLeft(nums, k);
    int rightIdx = searchRight(nums, k);
    int res = rightIdx - leftIdx + 1;

    // cout << "leftIdx: " << leftIdx << endl;
    // cout << "rightIdx: " << rightIdx << endl;
    // cout << "res: " << res << endl;

    if(leftIdx == -1 || rightIdx == -1)
        return 0;
    return res;
}

int main()
{
    vector<int> nums{1,3,4,5};
    int k = 6;
    int res = GetNumberOfK(nums, k);
    cout << res << endl;
    return 0;
}