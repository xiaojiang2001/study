#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

bool traversal(TreeNode* root1, TreeNode* root2)
{
    // 子树为空，一定返回true
    if(root2 == nullptr)
        return true;
    // 这时子树不为空，父树为空，返回false;
    if(root1 == nullptr)
        return false;

    if(root1->val != root2->val)
        return false;

    bool left  = traversal(root1->left, root2->left);
    bool right = traversal(root1->right, root2->right);

    return left && right;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    bool left = false;
    bool right = false;

    if (pRoot1 != nullptr && pRoot2 != nullptr) 
    {
        // 判断当前节点
        if (traversal(pRoot1, pRoot2))
            return true;
        // 递归判断左子树
        if (pRoot1->left)
            left = HasSubtree(pRoot1->left, pRoot2);
        // 递归判断右子树
        if (pRoot1->right)
            right = HasSubtree(pRoot1->right, pRoot2);
    }
    return left || right;
}


int main()
{

}