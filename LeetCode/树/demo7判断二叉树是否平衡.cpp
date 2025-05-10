
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归，不平衡返回-1
int depth(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    int left  = depth(node->left);
    int right = depth(node->right);

    // 下面已经不平衡了
    if(left == -1 || right == -1)
        return -1;

    // 当前触发不平衡
    if(abs(left - right) > 1)
        return -1;
    
    return max(left, right) + 1;
}

bool getBalance(TreeNode *node, int* depth)
{
    if(node == nullptr) {
        *depth = 0;
        return true;
    }

    int left, right;            // 左右高度
    bool leftRet  = getBalance(node->left,  &left);
    bool rightRet = getBalance(node->right, &right);

    // 已经不平衡
    if(!leftRet || !rightRet)
        return false;
    if(abs(left - right) > 1)
        return false;
    *depth = max(left, right) + 1;
    return true;
}

bool isBalanced(TreeNode* root) 
{
    if(root == nullptr)
        return true;
    int depth;
    bool ret = getBalance(root, &depth);
    return ret;
}











int depth(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    int left  = depth(node->left);
    int right = depth(node->right);

    // 有一边已经不平衡
    if(left == -1 || right == -1)
        return -1;
    // 差值大 触发不平衡
    if(abs(left - right) > 1)
        return -1;
    // 平衡 返回高度
    return max(left, right) + 1;
}

bool getBalance(TreeNode* node, int *depth)
{
    if(node == nullptr) { 
        *depth = 0;
        return true;
    }
    int left = 0;
    int right = 0;
    if(getBalance(node->left, &left) && getBalance(node->right, &right)) 
    {
        *depth = max(left, right) + 1;
        if(abs(left - right) <= 1)
            return true;
        else
            return false;
    }
    return false;
}

bool isBalanced(TreeNode* root) {
    if(root == nullptr)
        return true;
    int depth = 0;
    bool ret = getBalance(root, &depth);
    return ret;
}