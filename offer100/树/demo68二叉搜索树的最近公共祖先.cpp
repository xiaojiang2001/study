#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(int x):val(x), left(nullptr),right(nullptr){}
};

int lowestCommonAncestor(TreeNode* root, int p, int q) {
    if(root->val == q || root->val == q)
        return root->val;

    if(root->val > p && root->val > q)
        return lowestCommonAncestor(root->left,  p,  q);
    else if(root->val < p && root->val < q)
        return lowestCommonAncestor(root->right,  p,  q);
        
    return root->val;
}

int main()
{
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(1);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    int ret = lowestCommonAncestor(root, 0 ,5);
    cout << "ret:" << ret << endl;
    return 0;
}