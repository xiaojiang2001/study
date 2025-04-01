#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void PrintFromTopToBottom(TreeNode* root) 
{
    vector<int> res;
    if(root == nullptr)
        return ;

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    int level = 1;      // 层数
    while (!st1.empty() || !st2.empty())
    {
        int n = max(st1.size(), st2.size());
        for (int i = 0; i < n; i++)
        {
            // 奇数层
            if(level % 2 == 1)
            {
                TreeNode*  cur = st1.top();
                st1.pop();
                cout << cur->val << " ";
                if(cur->left)
                    st2.push(cur->left);
                if(cur->right)
                    st2.push(cur->right);
            }
            else           // 偶数层
            {
                TreeNode*  cur = st2.top();
                st2.pop();
                cout << cur->val << " ";
                if(cur->right)
                    st1.push(cur->right);
                if(cur->left)
                    st1.push(cur->left);
            }
        }
        level++;
        cout << endl;
    } 
}



int main()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

    PrintFromTopToBottom(root);
}