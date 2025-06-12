#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(nullptr), right(nullptr) {}
};


bool isSymmetical(TreeNode* root)
{

}


// root1中左右    root2中右左
bool judge(TreeNode *root1, TreeNode *root2)
{
    if(root1 == nullptr && root2 == nullptr)    // 都为空
        return true;
    if(root1 == nullptr || root2 == nullptr)    // 一边为空 
        return false;
    
    // 中 当前节点不相同
    if(root1->val != root2->val)
        return false;
    
    // 分别比较root1的左子树与root2的右子树 
    // 以及root1的右子树与root2的左子树 
    return judge(root1->left, root2->right) && judge(root1->right, root2->left);
}