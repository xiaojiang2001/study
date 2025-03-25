#include <bits/stdc++.h>

using namespace std;

// 向下调整某个
// n 表示需要剩余需要调整的节点个数
// k 表示需要调整的某个节点
void downAdjust(vector<int> &nums, int n, int k)
{
    int i = k;      // 自身节点
    int j = 2 * k;  // 下面最大的节点，默认为左节点
    while (j <= n)
    {
        // 右节点 > 大于左节点
        if(j + 1 <= n && nums[j+1] > nums[j])
            j++;
        if(nums[i] < nums[j])
        {
            // 子孩子更大
            swap(nums[i], nums[j]);

            // 进入下一层
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
}
// n 表示需要排序的元素个数，len = size - 1, 这里以1为起始
void heapSort(vector<int> &nums, int len)
{
    // 建堆
    for (int i =  len / 2; i >= 1; i--)
        downAdjust(nums, len, i);
    
    // 排序
    for (int i = len; i >= 1; i--) {
        // 排序是和堆顶交换
        swap(nums[1], nums[i]);
        // 然后调节堆顶
        downAdjust(nums, i-1, 1);   
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