#include <bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

// 递归匹配函数
bool traversal(TreeNode* pRoot1, TreeNode* pRoot2)
{
    // B匹配结束 没了 A可有可无
    if(pRoot2 == nullptr)
        return true;
    // A没了，B还有
    if(pRoot1 == nullptr && pRoot2 != nullptr)
        return false;
    // 致此，A, B一定有
    if(pRoot1->val != pRoot2->val)
        return false;

    // 左右都有 且当前节点值相等
    bool left = traversal(pRoot1->left, pRoot2->left);
    bool right = traversal(pRoot1->right, pRoot2->right);
    if(left && right)
        return true;
    return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    // A B 都有
    bool cur = traversal(pRoot1, pRoot2);           // 当前就匹配
    bool left = HasSubtree(pRoot1->left, pRoot2);   // 递归左子树
    bool right = HasSubtree(pRoot1->right, pRoot2); // 递归右子树
    return cur || left || right;
}


int main()
{

}