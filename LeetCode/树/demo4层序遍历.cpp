#include <bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    vector<int> path;
    queue<TreeNode*> que;
    if(root == nullptr)
        return res;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
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

}