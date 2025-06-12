#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};



// 1. 空节点 || 叶子节点   返回
// 2. 交换左右子树
// 3. 递归处理左右子树