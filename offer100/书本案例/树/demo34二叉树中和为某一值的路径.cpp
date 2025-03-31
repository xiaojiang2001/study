#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* left;
    ListNode* right;
    ListNode(int x):val(x), left(nullptr), right(nullptr) {}
};

vector<ListNode*> path;

void backtracking(ListNode* node, int target, int sum)
{
    if(node == nullptr)
        return;
    
    // 当前处理逻辑
    path.push_back(node);
    sum += node->val;
    
    if(sum == target && node->left == nullptr && node->right == nullptr) 
    {
        vector<ListNode*>::iterator it = path.begin();
        for ( ; it < path.end() - 1; it++) {
            cout << (*it)->val << " -> ";
        }
        cout << (*it)->val << endl;
        return;
    }

    // 递归左有子树 + 回溯
    if(node->left) 
        backtracking(node->left, target, sum);
        
    // 递归右子树 + 回溯
    if(node->right) 
        backtracking(node->right, target, sum);

    sum -= node->val;
    path.pop_back();
    
}

void FindPath(ListNode* pRoot, int target)
{
    if(pRoot == nullptr)
        return;
    backtracking(pRoot, target, 0);
}

int main()
{
    ListNode* root = new ListNode(10);
    root->left  = new ListNode(5);
    root->right = new ListNode(12);
    root->left->left  = new ListNode(4);
    root->left->right = new ListNode(7);
    FindPath(root, 22);
    return 0;
}