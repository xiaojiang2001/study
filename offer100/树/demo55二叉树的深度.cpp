#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int TreeDepth(TreeNode* pRoot) {
    queue<TreeNode*> que;
    if(pRoot == nullptr)
        return 0;
    
    int res = 0;
    que.push(pRoot);
    while (!que.empty())
    {
       
        int size = que.size();       // 获取每一层的节点个数
        res++;                       // 层数++
        // 遍历每一层的节点
        while (size--)
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
    }
    return res;
}

int main()
{

    return 0;
}