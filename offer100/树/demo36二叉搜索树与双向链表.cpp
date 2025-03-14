#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* head = nullptr;
TreeNode* pre  = nullptr;
void traversal(TreeNode* root)
{
    if(root == nullptr)
        return;
    // 递归左子树 找到最最左边的节点
    traversal(root->left);
    // 初始化头节点
    if(pre == nullptr) {
        head = root;
        pre  = root;
    }
    else {
        root->left = pre;
        pre->right = root;
        pre = root;
    }
    // 遍历右子树
    traversal(root->right);
}

TreeNode* Convert(TreeNode* pRootOfTree) {
    if(pRootOfTree == nullptr)
        return nullptr;
    traversal(pRootOfTree);
    return head;
}

int main()
{

}