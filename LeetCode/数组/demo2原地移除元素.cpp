#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    int fast = 0;
    for (fast = 0; fast < nums.size(); fast++)
    {
        if(nums[fast] != val)
            nums[slow++] = nums[fast];
    }
    return slow;
}

int main()
{
    return 0;
}