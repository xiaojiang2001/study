#include <bits/stdc++.h>

using namespace std;

// 不存在返回-1
int searchFirstK(vector<int>& nums, int k)
{
    if(nums.empty())
        return -1;
    
    int left = 0;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;
    int res = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == k)  {
            // 找到最左边的K
            if(mid == 0 || mid > 0 && nums[mid - 1] != k){ 
                res = mid;
                break;
            }
            else
                right = mid - 1;
        }
        else if(nums[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }  
    return res;
}

int searchLastK(vector<int>& nums, int k)
{
    if(nums.empty())
        return -1;
    
    int len = nums.size();
    int left = 0;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;
    int res = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == k)  {
            // 找到最右边的K
            if(mid == len -1  || mid < len -1  && nums[mid + 1] != k){ 
                res = mid;
                break;
            }
            else
                left = mid + 1;
        }
        else if(nums[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }  
    return res;
}

int GetNumberOfK(vector<int>& nums, int k) 
{
    if(nums.empty() && k == 0)
        return 0;
    if(nums.empty())
        throw runtime_error("valied params");
    
    int num = 0;
    int leftIdx  = searchFirstK(nums, k);
    int rightIdx = searchLastK(nums, k);
    
    if(leftIdx > -1 && rightIdx > -1)
        num = rightIdx - leftIdx + 1;

    return num;
}



int main()
{
    return 0;
}