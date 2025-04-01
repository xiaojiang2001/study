#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* traversal(TreeNode* root)
{

    
}



TreeNode* Convert(TreeNode* pRootOfTree)
{
    TreeNode* pre = nullptr;
    TreeNode* cur = pRootOfTree;
    if(pRootOfTree == nullptr)
        return nullptr;
    
    // 找起点
    while (cur->left) {
        cur = cur->left;
    }
    

}