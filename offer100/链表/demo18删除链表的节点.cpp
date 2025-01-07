#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};


ListNode* deleteNode(ListNode* head, int val) 
{
    if(head == nullptr)
        return nullptr;
    // 删除头节点
    if(val == head->val)
        return head->next;
    // 删除非头节点
    ListNode *cur = head;
    while (cur->next)
    {
        if(cur->next->val == val) {
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }
    return head;
}


int main()
{

    return 0;
}