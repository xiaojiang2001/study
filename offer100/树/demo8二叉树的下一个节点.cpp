#include <bits/stdc++.h>

using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
};

// 队列保存中序遍历结果
void traversal(TreeLinkNode* root, queue<TreeLinkNode*> que)
{
    if(root == nullptr)
        return;
    traversal(root->left, que);     // 左
    que.push(root);                 // 中
    traversal(root->right, que);    // 右
}


TreeLinkNode* GetNext(TreeLinkNode* pNode) 
{
    queue<TreeLinkNode*> que;
    traversal(pNode, que);
}


int main()
{
    TreeLinkNode* root = new TreeLinkNode(8);
    root->left = new TreeLinkNode(6);
    root->right = new TreeLinkNode(10);
    root->left->left = new TreeLinkNode(5);
    root->left->right = new TreeLinkNode(7);
    root->right->left = new TreeLinkNode(9);
    root->right->right = new TreeLinkNode(11);
    TreeLinkNode* retRoot = GetNext(root);
    cout << "next val:" << retRoot->val << endl;
    return 0;
}