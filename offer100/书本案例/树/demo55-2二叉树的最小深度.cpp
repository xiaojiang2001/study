#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

// 二叉树最小的深度
int minDepth(TreeNode* root) 
{
    if(root == nullptr)
        return 0;
    
    int left =  minDepth(root->left);
    int right =  minDepth(root->right);
    
    // 左空 右不空
    if(root->left == nullptr && root->right)
        return right + 1;
    
    // 左不空 右空
    if(root->left && root->right == nullptr)
        return left + 1;
    
    // 左右空或左右不空
    int res =  min(left, right) + 1;
    return res;
}

int main()
{

}