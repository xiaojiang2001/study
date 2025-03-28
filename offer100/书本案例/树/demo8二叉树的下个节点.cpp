#include <bits/stdc++.h>

using namespace std;


struct TreeLinkNode
{
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode *next;
    TreeLinkNode(int x):val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// 1. 有右子树: next = 右子树的左子树的最左节点
// 2. 没有右子树: 
//      (1): 当前为左子树：next = 父节点
//      (2): 当前为右子树：next = 负节点为左子树时候的父节点
// 想清楚以上情况和表示后再写代码

TreeLinkNode* GetNext(TreeLinkNode* pNode) 
{
    if(pNode == nullptr)
        return;
    TreeLinkNode* cur = pNode;
    // 有右子树: next = 右子树的左子树的最左节点
    if(cur->right != nullptr) {
        cur = cur->right;
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return cur;
    }
    // 没有右子树
    // (1) 当前为左节点
    if(pNode->next != nullptr && pNode->next->left == pNode) {
        return pNode->next;
    }

    // (2) 当前为右节点 父节点不为左子树
    while(cur->next != nullptr && cur->next->next != nullptr && 
            cur->next->next->left != cur->next) 
    {
        cur = cur->next;
    }
    // 不存在
    if(cur->next == nullptr || cur->next->next == nullptr)
        return nullptr;
    
    // 真的存在了 父节点为左子树
    return cur->next->next;
}

int main()
{
    return 0;
}