#include <bits/stdc++.h>

using namespace std;

// 向下调整某个节点
void downAdjust(vector<int>& nums, int k, int n)    
{
    // 左右孩子
    int i = k;
    int j = 2 * k;
    // 判断是否调整到了叶节点
    while (j <= n)      
    {
        // j保存较大孩子的下标
        if(j+1 <= n && nums[j+1] > nums[j])
            j++;
        if(nums[i] < nums[j]) {
            swap(nums[i], nums[j]);
            // 向下遍历
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}

// n 表示元素个数
void heapSort(vector<int>& nums, int n)
{
    // 建堆
    for (int i = n/2; i >= 1; i--) {
        downAdjust(nums, i, n);     // 向下调整某个节点
    }
    // 排序 每轮堆顶换到最后，向下调整新的堆顶
    for (int i = n; i >= 1; i--) {
        swap(nums[1], nums[i]);
        downAdjust(nums, 1, i-1);
    }
}

int main()
{
    vector<int> nums{-1,7,19,18,27,53,30,51,48,48,60};
    heapSort(nums, 10);
    for (int i = 1; i <= 10; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}