#include <bits/stdc++.h>

using namespace std;

// 1. 最长递增子序列
/*
// 动归法:
int lengthOfLIS(vector<int>& nums) {
    // dp[i]: 表示考虑下标i形成的最长递增子序列的长度
    vector<int> dp(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
                dp[i] = max( dp[i], dp[j] + 1);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << "i = " << i << " dp[i] = " << dp[i] << endl;
    }
    
    return *max_element(dp.begin(), dp.end());
}

// 二分 + 贪心
int lengthOfLIS(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();
    
    int len = 1;
    // 长度为 i 的最长上升子序列的末尾元素的最小值
    vector<int> d(nums.size() + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i] > d[len]) {
            len++;
            d[len] = nums[i];
        }
        else
        {
            int left = 0;
            int right = len;
            int pos = 0;
            // 左闭右开
            while (left <= right)
            {
                int mid = (left + right) >> 1;
                if(d[mid] < nums[i]) {
                    pos = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            d[pos + 1] = nums[i];
        }
    }
    return len;
}
*/


// 2. 最长连续递增子序列
/*
// 动规
int findLengthOfLCIS(vector<int>& nums) {
    // 考虑下标为i的最长连续递增子序列长度
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i] > nums[i-1])
            dp[i] = max(dp[i-1] + 1, dp[i]);
    }
    return *max_element(dp.begin(), dp.end());
}

// 贪心-抓住是连续的，找到小的更新数据
int findLengthOfLCIS(vector<int>& nums) {
    int len = 1;
    int res = 1;
    for (int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i-1]) 
            len++;
        else 
            len = 1;    // 贪心
        res = max(res, len);
    }
    return res;
}
*/


// 3. 最大子序和
/*
// 思路1：一眼贪心 加到负数则舍弃之前的累加值（贪心）
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum < 0)
            sum = 0;
    }
    return maxSum;
}

// 动规似乎也比较简单好理解
int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size(), INT_MIN);
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
    }
    return *max_element(dp.begin(), dp.end());
}
*/

// 4. 最长公共子序列 LCS
int longestCommonSubsequence(string text1, string text2) {
    //dp[i][j]: 当 text1 以 i-1 为下标, text2 以 j-1 为下标形成的最长重复子数组长度
    // 长度为 i 的text1和长度为 j 的text2的字符串
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}


// 5. 判断子序列
/*
bool isSubsequence(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    if(dp[s.size()][t.size()] == s.size())
        return true;
    return false;
}

bool isSubsequence(string s, string t) {
    int slow = 0;
    int fast = 0;
    while (fast < t.size())
    {
        if(t[fast] == s[slow])
            slow++;   
        fast++;
    }
    if(slow == s.size())
        return true;
    return false;
}
*/


// 6. 不同的子序列
// s = "babgbag", t = "bag"
int numDistinct(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    // t = 0, dp[i][0] = 1;
    for (int i = 0; i < s.size(); i++) 
        dp[i][0] = 1;
    for (int j = 1; j <= t.size(); j++) 
	    dp[0][j] = 0; 

    for (size_t i = 1; i <= s.size(); i++)
    {
        for (size_t j = 1; j <= t.size(); j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[s.size()][t.size()];
}

//7. 连个字符串的删除操作
//单词word1和word2，返回使得word1和word2相同所需的最小步数
int minDistance(string word1, string word2) {
    // dp[i][j]: 当 text1 以 i-1 为下标, text2 以 j-1 为下标形成的最长重复子数组长度
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

    for (int i = 1; i <= word1.size(); i++)
    {
        for (int j = 1; j <= word2.size(); j++)
        {
            
        }
    }

}

int main()
{
    vector<int> vec{1,3,6,7,9,4,10,5,6};
    string str1 = "abc";
    string str2 = "ahbgdc";
    int len = numDistinct(str1, str2);
    cout << "len: " << len << endl;
    return 0;
}