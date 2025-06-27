#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// 模板题：请熟记

// 思路1：中序遍历一定是有序的
void traversal(const TreeNode* root, vector<int>& vec)
{
    if(root == nullptr)
        return;
    
    traversal(root->left, vec);         // 左
    vec.push_back(root->val);           // 中
    traversal(root->right, vec);        // 右
}

bool isValidBST(TreeNode* root) {
    if(root == nullptr)
        return false;
    vector<int> vec;
    traversal(root, vec);
    for (size_t i = 0; i < vec.size() - 1; i++) {
        if(vec[i] >= vec[i+1])
            return false;
    }
    return true;
}

// 思路2：递归遍历 + 双指针
TreeNode* pre = nullptr;
bool traversal(TreeNode* root)
{
    if(root == nullptr)
        return true;
    
    bool left = traversal(root->left);

    if(pre != nullptr && pre->val >= root->val)
        return false;
    pre = root;

    bool right = traversal(root->right);

    return left && right;
}

bool isValidBST(TreeNode* root) {
    if(root == nullptr)
        return false;
    return traversal(root);
}


// 思路3：迭代遍历 + 双指针
bool isValidBST(TreeNode* root)
{
    if(root == nullptr)
        return false;
    
    stack<TreeNode*> st;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;

    while (cur != nullptr || !st.empty())
    {
        if(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        else {
            cur = st.top();
            st.pop();

            if(pre != nullptr && pre->val >= cur->val)
                return false;
            pre = cur;

            cur = cur->right;
        }
    }
    return true;
}

// 习题,二叉搜索树中的众数,结合剑指offer的39题(数组中超过一半的数字)，方法二思想，
// 利用两个变量，分别保存当前的数字以及次数
vector<int> findMode(TreeNode* root) {
    if(root == nullptr)
        return vector<int> {};

    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    stack<TreeNode*> st;
    vector<int> vec;
    int cnt = 0;
    int maxCnt = 0;

    while (cur != nullptr || !st.empty())
    {
        if(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        else 
        {
            cur = st.top();
            st.pop();

            // 处理cnt
            if(pre == NULL)			//最初
                cnt = 1;
            else if(pre->val == cur->val)	//数值相同 累加
                cnt++;	
            else 					//新数据
                cnt = 1;
            pre = cur;				//更新旧指针

            // 收集结果
            if(cnt == maxCnt)   
                vec.push_back(cur->val);
            else if(cnt > maxCnt) {
                maxCnt = cnt;
                vec.clear();				//☆有更长的频率 之前存入的结果都作废
                vec.shrink_to_fit();
                vec.push_back(cur->val);	//当前新的长度的数记得存进去
            }
            
            cur = cur->right;   //右
        }
    }

    return vec;
}


int main()
{

}