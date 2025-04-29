#include <bits/stdc++.h>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = nums1.size() - 1;
    cout << "idx: " << idx << endl;
    int tail1 = m - 1;
    int tail2 = n - 1;
    while (tail1 > -1 && tail2 > -1) 
    {
        if(nums1[tail1] <= nums2[tail2])
            nums1[idx--] = nums2[tail2--];
        else
            nums1[idx--] = nums1[tail1--];
    }

    //  num2剩下的
    while (tail2 > -1) {
        nums1[idx--] = nums2[tail2--];
    }
}

int main()
{
    vector<int> num1 = {2, 7, 10, 0, 0 ,0};
    vector<int> num2 = {3, 4, 5};
    merge(num1, 3, num2, num2.size());
    for (auto num :  num1) {
        cout << num << " ";
    }
}
