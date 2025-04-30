
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 思路1：二叉搜索树的中序遍历（递归 / 迭代）数组是有序的
// 思路2：双指针 + 前序遍历
// TreeNode* pre = nullptr;
// bool isValidBST(TreeNode* root) 
// {
//     if(root == nullptr)
//         return true;
//     // 左
//     bool left = isValidBST(root->left);

//     // 中
//     if(pre != nullptr && root->val <= pre->val)
//         return  false;
//     pre = root;

//     bool right = isValidBST(root->right);

//     return left && right;
// }

// 中序遍历迭代法
bool isValidBST(TreeNode* root) 
{
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (!st.empty() || cur)
    {
        // 左
        if(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }   
        else
        {
            // 中
            cur = st.top();
            st.pop();
            if(pre != nullptr && cur->val <= pre->val)
                return false;
            pre = cur;

            // 右
            cur = cur->right;
        }
    }
    return true;
}

int main()
{
    return 0;
}