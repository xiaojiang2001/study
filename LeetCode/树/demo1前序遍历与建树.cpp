#include <bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 前序遍历 思路1：递归遍历
void traversal(TreeNode* root, vector<int> & vec)
{
    if(root == nullptr)
        return;
    
    vec.push_back(root->val);
    traversal(root->left,  vec);
    traversal(root->right, vec);
}
// vector<int> preorderTraversal(TreeNode* root) {
//     vector<int> vec;
//     vec.clear();
//     traversal(root, vec);
//     return vec;
// }

// 思路2: 迭代遍历

vector<int> preorderTraversal(TreeNode* root) {
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
        if(node->right)             // 右 这是栈存放
            st.push(node->right);   
        if(node->left)
            st.push(node->left);    // 左
    }
    return res;
}


// 递归创建树
// 前序数组: vector<int> vec = {1,2,INT_MIN, INT_MIN, 3,INT_MIN, INT_MIN};
TreeNode* build_tree(vector<int> & vec, int &idx)
{
    if(idx >= vec.size() || vec[idx] == INT_MIN) {
        idx++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(vec[idx]);
    idx++;
    node->left  = build_tree(vec, idx);
    node->right = build_tree(vec, idx);
    return node;
}

// TreeNode* init_tree(vector<int>& vec)
// {
//     int idx = 0;
//     return build_tree(vec, idx);
// }

// 层序数组: vector<int> tree_data = {1, 2, 3, INT_MIN, 4, 5}
TreeNode* init_tree(vector<int>& vec)
{
    if(vec.empty() || vec[0] == INT_MIN)
        return nullptr;
    
    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(vec[0]);
    que.push(root);
    int i = 1;
    while (!que.empty() && i < vec.size())
    {
        TreeNode* cur = que.front();
        que.pop();

        // 左
        if(i < vec.size() && vec[i] != INT_MIN) {
            cur->left = new TreeNode(vec[i]);
            que.push(cur->left);
        }
        i++;

        if(i < vec.size() && vec[i] != INT_MIN){
            cur->right = new TreeNode(vec[i]);
            que.push(cur->right);
        }
        i++;
    }
    return root;
}

int main()
{
    vector<int> vec =  {1, 2, 3, INT_MIN, 4, 5};
    TreeNode* root = init_tree(vec);
    vector<int> res = preorderTraversal(root);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}