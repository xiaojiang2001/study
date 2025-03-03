#include <bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

int res = -1;
bool traversal(TreeNode* root, int o1, int o2)
{
    if(root == nullptr)
        return false;

    int leftRes  = traversal(root->left,  o1, o2);
    int rightRes = traversal(root->right, o1, o2);

    // 左右子树都有孩子
    if(leftRes && rightRes) {
        if(res == -1)               // 保存最近的父节点
            res = root->val;
        return true;
    }
    // 左右有一个子孩子
    else if(leftRes || rightRes)
    {
        if(root->val == o1 || root->val == o2){
            if(res == -1)               // 保存最近的父节点
                res = root->val;
        }
        return true;
    }

    // 左右都无子孩子 但值相等了
    if(root->val == o1 || root->val == o2)
        return true;
    // 左右都无子孩子，并且值都不相等
    return false;
}


int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    traversal(root, o1, o2);
    return res;
}


int main()
{

}