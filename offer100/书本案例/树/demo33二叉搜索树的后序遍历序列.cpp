#include <bits/stdc++.h>

using namespace std;

bool traveresal(vector<int> sequence)
{
    int len = sequence.size();
    if(len <= 1)
        return true;

    int rootVal = sequence[len - 1];
    // 找到左孩子的值下标 序列中 最后一个比 rootVal 小的值
    int idx = 0;
    while (idx < len && sequence[idx] < rootVal) {
        idx++;
    }
    int leftIdx = idx - 1;

    // 分割为 左右子数组
    vector<int> leftArray(sequence.begin(),  sequence.begin() + leftIdx + 1);
    vector<int> rightArray( sequence.begin() + leftIdx + 1, sequence.end() - 1);   // 不需要找right
    // 并且保证leftArray中的值 < rootVal, rightArray > rightArray
    auto pmax = max_element(leftArray.begin(),  leftArray.end());
    auto pmin = min_element(rightArray.begin(), rightArray.end());
    if( pmax != leftArray.end() && *pmax > rootVal ||
        pmin != rightArray.end() && *pmin < rootVal )
    return false;

    // 递归判断左右子数组构成的BST是否true
    bool leftBST  = traveresal(leftArray);
    bool rightBST = traveresal(rightArray);

    return leftBST && rightBST;
}

bool VerifySquenceOfBST(vector<int> sequence)
{
    if(sequence.size() == 0)
        return false;
    bool ret = traveresal(sequence);
    return ret;
}

int main()
{
    return 0;
}