
#include <bits/stdc++.h>

using namespace std;



struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



int getHeigh(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    int left  = getHeigh(node->left);
    int right = getHeigh(node->right);
    return max(left, right) + 1;
}


int calculateDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    return getHeigh(root);
}





int getMinDepth(TreeNode* node)
{
    if(node == nullptr)
        return 0;
    // 有左子树 无右子树
    if(node->left && !node->right)
        return getMinDepth(node->left) + 1;
    // 有右子树 无左子树
    if(!node->left && node->right)
        return getMinDepth(node->right) + 1;

    int left  = getMinDepth(node->left);
    int right = getMinDepth(node->right);
    return min(left, right) + 1;
}
int minDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    return getMinDepth(root);
}