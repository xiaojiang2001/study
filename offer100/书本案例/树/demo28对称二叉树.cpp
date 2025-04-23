#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

bool traversal(TreeNode* root1, TreeNode* root2)
{
    if(root1 == nullptr && root2 == nullptr) 
        return true;
    if(root1 == nullptr || root2 == nullptr)
        return false;

    if(root1->val != root2->val)
        return false;

    // 分开写
    return traversal(root1->left, root2->right) && traversal(root1->right, root2->left);
}

// 对称二叉树
bool isSymmetrical(TreeNode* pRoot) 
{
    return traversal(pRoot, pRoot);
}

int main()
{

}