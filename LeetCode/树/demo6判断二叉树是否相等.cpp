#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

bool traversal(TreeNode* p, TreeNode* q)
{
    if(p == nullptr && q == nullptr)
        return true;
    if(p == nullptr && q != nullptr || p != nullptr && q == nullptr)
       return false;
    
    // p!=null && q != null
    bool left  = traversal(p->left, q->left);
    bool right = traversal(p->right, q->right);
    if(left && right && p->val == q->val)
        return true;

    return false;
}



bool isSameTree(TreeNode* p, TreeNode* q) {
    return traversal(p, q);
}



int main()
{

}