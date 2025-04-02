#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* pre = nullptr;
TreeNode* head = nullptr;
void traversal(TreeNode* root)
{
    if(root == nullptr)
        return;
    
    // 左 递归处理左子树
    traversal(root->left);
    
    // 中
    if(pre == nullptr) {
        head = root;
        pre = root;
    }
    else {
        pre->right = root;
        root->left = pre;
        pre = root;
    }

    // 右 遍历右子树
    traversal(root->right);
}



TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(pRootOfTree == nullptr)
        return nullptr;
    traversal(pRootOfTree);
    return head;
}