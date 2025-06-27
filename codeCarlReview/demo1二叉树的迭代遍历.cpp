#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};

// 基础 + 模板，必须轻车熟路

// 前序 中左右
vector<int> preorderTraversal(TreeNode* root) 
{
    if(root == nullptr)
        return vector<int> {};

    vector<int> vec;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        // 中
        TreeNode* node = st.top();
        st.pop();
        vec.push_back(node->val);
        
        // 放入右  这是栈，先处理左
        if(node->right)
            st.push(node->right);

        // 放入左 后处理右
        if(node->left)
            st.push(node->left);
    }
    return vec;
}

// 中序遍历
vector<int> inorderTraversal(TreeNode* root)
{
    if(root == nullptr)
        return vector<int> {};
    
    vector<int> vec;
    stack<TreeNode*> st;
    TreeNode *cur = root;

    while (cur != nullptr || !st.empty())
    {
        // 左
        if(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        else {
            cur = st.top();
            st.pop();

            // 中
            vec.push_back(cur->val);

            // 右
            cur = cur->right;
        }
    }
    return vec;
}


vector<int> inorderTraversal(TreeNode* root)
{
    if(root == nullptr)
        return vector<int> {};

    vector<int> vec;
    stack<TreeNode*> st;

    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (cur != nullptr || !st.empty())
    {
        if(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();

            vec.push_back(cur->val);

            if(pre == nullptr){
                cur = cur->right;
                pre = cur;
            }
        }
    }
    
}
int main()
{

}