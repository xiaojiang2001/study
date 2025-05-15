#include <bits/stdc++.h>

using namespace std;

// 判断是否为偶数的函数
bool ivEvent(int num) {
    return num % 2 == 0;
}

vector<int> sortArrayByParity(vector<int>& nums, bool (*func)(int)) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        while (left < nums.size() && func(nums[left]))   // 找到第一个奇数
            left++;
        while (right >= 0 && !func(nums[right]))         // 找到第一个偶数
            right--;
        
        if(left < nums.size() && right >= 0 && left <= right)
            swap(nums[left++], nums[right--]);
    }
    return nums;
}

int main()
{
    vector<int> nums{1,3,6,5,7};
    vector<int> res = sortArrayByParity(nums, ivEvent);
    for (auto num : res)
        cout << num << " ";

    return 0;
}