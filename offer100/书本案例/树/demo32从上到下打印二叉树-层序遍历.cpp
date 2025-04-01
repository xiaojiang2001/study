#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};


vector<int> PrintFromTopToBottom(TreeNode* root) 
{
    vector<int> res;
    if(root == nullptr)
        return res;
    
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode*  cur = que.front();
            que.pop();
            res.push_back(cur->val);

            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);
        }
    }
    return res;    
}



int main()
{

}