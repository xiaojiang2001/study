#include <bits/stdc++.h>    

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};

vector<vector<int>> res;
vector<int> path;

void backtracking(TreeNode* root, int target, int currentSum) {
    if(currentSum > target || root == nullptr)
        return;

    // 添加当前节点到路径
    path.push_back(root->val);
    currentSum += root->val;
    
    // cout << "当前 currentSum: " << currentSum << endl;

    if(root->left == nullptr && root->right == nullptr && currentSum == target)
        res.push_back(path);

    // 递归处理左右子树
    backtracking(root->left, target, currentSum);
    backtracking(root->right, target, currentSum); 
    
    // 回溯，移除当前节点
    //  这行其实是多余的，每次进入的是值传递，每一轮的值已经被保存下来了
    // currentSum -= root->val; // currentSum 不需要回溯，因为是值传递
    path.pop_back();            // 需要回溯，因为是全局变量
}


int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    int val = 22;
    backtracking(root, val, 0);

    for (auto vec : res) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}