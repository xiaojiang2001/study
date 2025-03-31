#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    
    int left  = getHeight(root->left);
    int right = getHeight(root->right);

    // 不平衡了
    if(left == -1 || right == -1 || abs(left - right) > 1)
        return -1;

    // 平衡
    return max(left, right) + 1;
}

// 二叉树最小的深度
// bool isBalance(TreeNode* root) 
// {
//     if(root == nullptr)
//         return true;
//     int res = getHeight(root);
//     if(res == -1)
//         return false;
    
//     return true;
// }



// 记录每个节点的深度
bool balanced(TreeNode* root, int *depth)
{
    if(root == nullptr) {
        *depth = 0;
        return true;
    }

    int left, right;
    // 左右都平衡
    if(balanced(root->left, &left) && balanced(root->right, &right))
    {
        int diff = abs(left - right);
        if(diff <= 1) {
            *depth = max(left, right) + 1;
            return true;
        }
    }
    return false;
}

bool isBalanced(TreeNode* root)
{
    int depth = 0;
    bool ret = balanced(root, &depth);
    return ret;
}


int main()
{

}