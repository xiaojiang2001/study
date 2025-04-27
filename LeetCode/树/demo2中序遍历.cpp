#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};



// 思路1: 递归
void traversal(TreeNode* root, vector<int> &vec)
{
    if(root == nullptr)
        return;
    traversal(root->left, vec);
    vec.push_back(root->val);
    traversal(root->right, vec);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec;
    vec.clear();
    traversal(root, vec);
    return vec;
}

// 思路2: 迭代
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    res.clear();
    if(root == nullptr)
        return res;
    TreeNode* cur = root;
    stack<TreeNode*> st;

    while (cur != nullptr || !st.empty())
    {
        // 左
        if (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        else {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);    // 中
            cur = cur->right;           // 右
        }
    }
    
    return res;
}

