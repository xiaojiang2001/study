#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

void traversal(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    swap(pRoot->left, pRoot->right);
    traversal(pRoot->left);
    traversal(pRoot->right);
}


TreeNode* Mirror(TreeNode* pRoot) {
    traversal(pRoot);
    return pRoot;
}

void show(TreeNode *root)
{
    if(root == nullptr)
        return;
    
    cout << root->val << " ";
    show(root->left);
    show(root->right);
}

int main()
{
    TreeNode *root  = new TreeNode(8);
    root->left =  new TreeNode(6);
    root->right =  new TreeNode(10);
    root->left->left  =  new TreeNode(5);
    root->left->right =  new TreeNode(7);
    root->right->left =  new TreeNode(9);
    root->right->right =  new TreeNode(11);
    show(root);
    cout << endl;
    TreeNode *res = Mirror(root);
    show(res);
    cout << endl;

    return 0;
}