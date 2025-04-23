#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* traversal(TreeNode* root)
{
    if(root == nullptr)
        return nullptr;
    
    root->left = traversal(root->right);
    root->right = traversal(root->left);
    return root;
}


TreeNode* Mirror(TreeNode* pRoot) 
{
    if(pRoot == nullptr)
        return nullptr;
    pRoot->left = traversal(pRoot->right);
    pRoot->right = traversal(pRoot->left);
    return pRoot;
}

int main()
{

}