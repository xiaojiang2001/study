#include <bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 后序遍历 思路1：递归遍历
void traversal(TreeNode* root, vector<int> & vec)
{
    if(root == nullptr)
        return;
    
    traversal(root->left,  vec);
    traversal(root->right, vec);
    vec.push_back(root->val);
}
// vector<int> postorderTraversal(TreeNode* root) {
//     vector<int> vec;
//     vec.clear();
//     traversal(root, vec);
//     return vec;
// }

// 思路2: 迭代遍历
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> res;
    res.clear();
    if(root == nullptr)
        return res;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);   // 中
        if(node->left)
            st.push(node->left);    // 左
        if(node->right)             // 右 这是栈存放
            st.push(node->right);   
    }
    reverse(res.begin(), res.end());
    return res;
}

