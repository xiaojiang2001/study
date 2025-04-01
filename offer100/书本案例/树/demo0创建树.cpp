#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 通过数组初始化二叉树
TreeNode* buildTreeFromArray(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        // 左子节点
        if (i < arr.size() && arr[i] != -1) { // 假设 -1 表示 nullptr
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        // 右子节点
        if (i < arr.size() && arr[i] != -1) { // 假设 -1 表示 nullptr
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// 打印二叉树（中序遍历）
void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> values = {5, 3, 7, 2, 4, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1};

    TreeNode* root = buildTreeFromArray(values);

    cout << "In-order traversal of the binary tree: ";
    printInOrder(root);
    cout << endl;

    // 释放内存（在实际应用中，需要遍历树并删除每个节点）
    // 这里为了简化，没有实现完整的释放逻辑

    return 0;
}