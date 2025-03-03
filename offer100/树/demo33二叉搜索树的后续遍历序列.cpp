#include <bits/stdc++.h>

using namespace std;

bool traversal(vector<int> sequence) 
{
 int size = sequence.size();
    if(size <= 1)
        return true;
    
    int mid = -1;
    for (size_t i = 0; i < size; i++) {
        if(sequence[i] > sequence[size - 1]) {
            mid = i;
            break;
        }
    }
    // 数组递增
    if(mid == -1)
        return true;
    
    // 前后遍历数组
    vector<int> leftQue(sequence.begin(), sequence.begin() + mid);
    vector<int> rightQue(sequence.begin() + mid, sequence.end() - 1);

    // 中间节点小于右边节点
    if(sequence[size - 1] > *min_element(rightQue.begin(), rightQue.end()))
        return false;

    // 判断左右子树
    bool leftBST  = traversal(leftQue);
    bool rightBST = traversal(rightQue);

    if(leftBST && rightBST)
        return true;
    return false;
}


//判断一个数组是不是某二叉搜索树的后序遍历的结果
bool VerifySquenceOfBST(vector<int> sequence) 
{
    if(sequence.size() == 0)
        return false;
    bool ret = traversal(sequence);
    return ret;
}

int main()
{
    vector<int> sequence{};
    bool res = VerifySquenceOfBST(sequence);
    cout <<  res << endl;
}