#include <bits/stdc++.h>

using namespace std;


struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode(int x):val(x),left(nullptr), right(nullptr) {}
};



TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    
}


void show(TreeLinkNode *root)
{
    if(root == nullptr)
        return;
    
    // 中序遍历
    show(root->left);
    cout << root->val << " ";
    show(root->right);
}

int main()
{
    TreeLinkNode *root  = new TreeLinkNode(8);
    root->left =  new TreeLinkNode(6);
    root->right =  new TreeLinkNode(10);
    root->left->left  =  new TreeLinkNode(5);
    root->left->right =  new TreeLinkNode(7);
    root->right->left =  new TreeLinkNode(9);
    root->right->right =  new TreeLinkNode(11);
    show(root);
    cout << endl;
    
    return 0;
}