#include <iostream>
#include <vector>

using namespace std;

vector<int> calculate(const vector<int>& nums, int n) 
{
    if (n == 0) {
        return {};
    }

    // dp[i]: 表示以第 i 个守护者的数字为结尾的最长不下降子序列的和
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = nums[i];
    }

    // 查找0-i 之间比i小的数
    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (nums[j] <= nums[i]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }

    return dp;
}



int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    vector<int> result = calculate(nums, n);

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

}