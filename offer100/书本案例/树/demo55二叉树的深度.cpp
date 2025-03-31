#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

// 二叉树的深度 == 根节点的高度
int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return 0;
    
    int leftHeight  = TreeDepth(pRoot->left);
    int rightHeight = TreeDepth(pRoot->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{

}