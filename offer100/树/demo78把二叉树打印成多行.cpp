#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};



vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> res;
    if(pRoot == nullptr)
        return res;
    queue<TreeNode*> que;
    que.push(pRoot);
    int size = 0;       // 每一行个数
    vector<int> path;   // 每一行的路径
    while (!que.empty())
    {
        size = que.size();
        path.clear();
        while (size--)
        {
            TreeNode* node = que.front();
            que.pop();
            path.push_back(node->val);
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
        res.push_back(path);
    }
    return res;
}


int main()
{


    return 0;
}