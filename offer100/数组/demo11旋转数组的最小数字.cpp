#include <iostream>
#include <vector>

using namespace std;


int minNumberInRotateArray(vector<int>& nums) 
{
    int minVal = 10001;
    int n = nums.size();
    int left = 0;
    int right = n-1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] < minVal)
            minVal = nums[mid];
        // 中间值小于右边
        if(nums[mid] < nums[right])
            right = mid - 1;
        // 中间值大于右边
        else if(nums[mid] > nums[right])
            left = mid + 1; 
        // 中间值等于右边 一个一个试
        else if(nums[mid] == nums[right])  
            right--;     
    }
    return minVal;
}

int main()
{
    vector<int> nums{2,2,2,1,2};
    int minVal = minNumberInRotateArray(nums);
    cout << minVal << endl;
    return 0;
}