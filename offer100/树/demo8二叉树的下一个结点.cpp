#include <bits/stdc++.h>

using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};


TreeLinkNode* GetRoot(TreeLinkNode* pNode)
{
    if(pNode->next == nullptr)
        return pNode;
    // 获取父节点
    TreeLinkNode* next = GetRoot(pNode->next);
    return next;
}

void Inorder(TreeLinkNode* root, vector<TreeLinkNode*> &vec)
{
    if(root == nullptr)
        return;
    
    Inorder(root->left, vec);
    vec.push_back(root);
    Inorder(root->right, vec);
}

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    TreeLinkNode* root = GetRoot(pNode);    // 获取头节点
    vector<TreeLinkNode*> vec;  // 中序遍历结果容器
    Inorder(root, vec);         // 中序遍历
    // 寻找下个节点
    for (int i = 0; i < vec.size(); i++) {
        if(vec[i] == pNode && i != vec.size()-1) {
            return vec[i+1];
        }
    }
    return nullptr;
}


int main()
{
    return 0;
}