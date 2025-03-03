#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(int x):val(x), left(nullptr),right(nullptr){}
};


// 计算最小深度
int getHight(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    int leftDepth = 0;
    int rightDepth = 0;
    leftDepth = getHight(root->left);
    rightDepth = getHight(root->right);
    return max(leftDepth, rightDepth) + 1;
}
// 遍历
bool traversal(TreeNode* root)
{
    if(root == nullptr)
        return true;
    
    int leftDepth = getHight(root->left);
    int rightDepth = getHight(root->right);
    // 左右不平衡了
    if(abs(leftDepth - rightDepth) > 1)
        return false;
    
    // 判断左右子树是否平衡
    bool leftTree = traversal(root->left);
    bool rightTree = traversal(root->right);
    if(leftTree && rightTree)
        return true;
    return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    if(pRoot == nullptr)
        return true;
    bool ret = traversal(pRoot);
    return ret;
}

int main()
{
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    bool ret = IsBalanced_Solution(root);
    cout << "ret:" << ret << endl;
    return 0;
}
