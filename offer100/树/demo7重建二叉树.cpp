#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
// preOrder: 1,2,4,7,3,5,6,8
// vinOrder: 4,7,2,1,5,3,8,6

TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
    if(preOrder.size() == 0 || vinOrder.size() == 0)
        return nullptr;
    // 封装根节点
    TreeNode* root = new TreeNode(preOrder[0]);
    // 确定头节点
    int mid = find(vinOrder.begin(), vinOrder.end(), preOrder[0]) - vinOrder.begin();
    // 左子树的前序中序数组
    vector<int> leftPreOrder(preOrder.begin() + 1, preOrder.begin() + mid + 1);
    vector<int> leftVinOrder(vinOrder.begin(), vinOrder.begin() + mid);
    // 右子树的前序中序数组
    vector<int> rightPreOrder(preOrder.begin() + mid + 1, preOrder.end());
    vector<int> rightVinOrder(vinOrder.begin() + mid + 1, vinOrder.end());
    // 构造左右子树
    root->left  = reConstructBinaryTree(leftPreOrder, leftVinOrder);
    root->right = reConstructBinaryTree(rightPreOrder, rightVinOrder);

    return root;
}

int main()
{
    return 0;
}