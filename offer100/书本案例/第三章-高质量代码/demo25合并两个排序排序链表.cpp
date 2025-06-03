#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

ListNode* init_link(vector<int>& vec)
{
    if(vec.empty())
        return nullptr;
    ListNode* root = new ListNode(vec[0]);
    ListNode* cur = root;
    for (int i = 1; i < vec.size(); i++)
    {
        ListNode* node = new ListNode(vec[i]);
        cur->next = node;
        cur = cur->next;
    }
    return root;
}

void delete_link(ListNode* root)
{
    while (root != nullptr)
    {
        ListNode* temp = root;
        root = root->next;
        delete temp;
    }
}

void show_link(ListNode* root)
{
    ListNode* cur = root;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

/*****************递归******************/
/*
ListNode* merge(ListNode* root1, ListNode* root2)
{
    // 处理边界情况 
    if(root1 == nullptr)    return root2;
    if(root2 == nullptr)    return root1;

    ListNode* mergeHead = nullptr;
    if(root1->val < root2->val) {
        mergeHead = root1;
        mergeHead->next = merge(root1->next, root2);
    }
    else {
        mergeHead = root2;
        mergeHead->next = merge(root1, root2->next); 
    }
    return mergeHead;
}
*/



/*****************迭代******************/
ListNode* merge(ListNode* root1, ListNode* root2)
{
    ListNode* dummyHead = new ListNode(-1);
    ListNode* cur = dummyHead;
    // 每次衔接俩链表中小的节点
    while (root1 != nullptr && root2 != nullptr)
    {
        if(root1->val < root2->val) {
            cur->next = root1;
            root1 = root1->next;
        }
        else {
            cur->next = root2;
            root2 = root2->next;
        }
        cur = cur->next;
    }
    // 衔接剩下的一支链表
    cur->next = root1 != nullptr? root1 : root2;

    return dummyHead->next; 
}

int main()
{
    vector<int> vec1{1,3,5,7};
    vector<int> vec2{2,4,6,8};
    ListNode* root1 = init_link(vec1);
    ListNode* root2 = init_link(vec2);
    cout << "链表1: ";
    show_link(root1);
    cout << "链表2: ";
    show_link(root2);

    ListNode* mergeHead = merge(root1, root2);
    cout << "合并后: ";
    show_link(mergeHead);
    return 0;
}