#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从当前节点出发，判断pRoot2是否在pRoot1中
bool traversal(TreeNode* pRoot1, TreeNode* pRoot2)
{
    // 注意 pRoot2 == null  返回true
    if(pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr)
        return false;

    if(pRoot1->val != pRoot2->val)
        return false;
    
     // 递归左右子树
    bool left  = traversal(pRoot1->left, pRoot2->left);
    bool right = traversal(pRoot1->right, pRoot2->right);

    return left && right;
}


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    bool left = false;
    bool right = false;

    if(pRoot1 != nullptr && pRoot2 != nullptr)
    {
        // 判断当前节点
        if(traversal(pRoot1, pRoot2))
            return true;
        // 递归判断左子树
        if(pRoot1->left)
            left = HasSubtree(pRoot1->left, pRoot2);
        // 递归判断右子树
        if(pRoot1->right)
            right = HasSubtree(pRoot1->right, pRoot2);
    }
    return left || right;
}

int main()
{
    return 0;
}