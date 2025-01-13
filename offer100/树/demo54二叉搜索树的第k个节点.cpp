#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> vec;
void traversal(TreeNode* proot)
{
    if(proot == nullptr)
        return;

    // 二叉搜索树 递增
    traversal(proot->left);
    vec.push_back(proot->val);
    traversal(proot->right);
}

int KthNode(TreeNode* proot, int k) {
    if(proot == nullptr)
        return -1;
    traversal(proot);
    if(k > vec.size() || k <= 0)
        return -1;
    return vec[k-1];
}

int main()
{
    return 0;
}