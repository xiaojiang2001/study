#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};



vector<int> PrintFromTopToBottom(TreeNode* root) 
{
    if(root == nullptr)
        return vector<int> {};
        
    vector<int> res;    //  结果
    queue<TreeNode*> que;     // 层序遍历队列
    que.push(root);
    while (!que.empty())
    {
        TreeNode *node = que.front();
        que.pop();
        res.push_back(node->val);
        if(node->left)  
            que.push(node->left);
        if(node->right)
            que.push(node->right);
    }
    return res;
}


int main()
{

    return 0;
}