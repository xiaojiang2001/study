#include <bits/stdc++.h>

using namespace std;


// 二分查找关键是要有个比较的对象，而不是左右值比较
int minNumberInRotateArray(vector<int>& nums) 
{
    if(nums.empty())
        throw new std::runtime_error("Invalid parameters");


    // 3 4 5 1 2
    int left = 0;
    int right = nums.size() - 1;
    int mid = (right + left) / 2;
    int minVal = 10001;
    while (left <= right)
    {            
        mid = (right + left) / 2;
        if(nums[mid] < minVal)
            minVal = nums[mid];

        if(nums[mid] > nums[right])
            left = mid + 1;
        else if(nums[mid] < nums[right])
            right = mid - 1;    
        else        // 相等
            right--;
    }
    return minVal;
}



int main()
{

}