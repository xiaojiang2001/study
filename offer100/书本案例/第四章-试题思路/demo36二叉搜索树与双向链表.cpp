#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 中序遍历 左中右 迭代法
/*
TreeNode* Convert(TreeNode* pRootOfTree) {
    if(pRootOfTree == nullptr)
        return nullptr;

    stack<TreeNode*> st;
    TreeNode* cur = pRootOfTree;
    TreeNode* pre = nullptr;
    TreeNode* root = nullptr;

    while (cur != nullptr || !st.empty())
    {
        // 左
        if(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();
            // 初始化头节点
            if(root == nullptr)
                root = cur;

            // 中
            if(pre != nullptr){
                cur->left = pre;
                pre->right = cur;
            }

            // 右
            pre = cur;
            cur = cur->right;
        }
    }
    return root;
}
*/

// 中序遍历 左中右 递归法
TreeNode* head = nullptr;
TreeNode* pre = nullptr;
void traversal(TreeNode* root)
{
    if(root == nullptr)
        return;

    // 左
    traversal(root->left);

    if(pre == nullptr) {
        head = root;
        pre = head;
    }
    else {
        root->left = pre;
        pre->right = root;
        pre = root;
    }
    // 右
    traversal(root->right);
}


TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(pRootOfTree == nullptr)
        return nullptr;
    
    traversal(pRootOfTree);
    return head;
}



int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(14);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);

    TreeNode* res = Convert(root);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->right;
    }

    return 0;
}   