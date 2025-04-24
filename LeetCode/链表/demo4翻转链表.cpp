#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路1: 前后指针
ListNode* trainningPlan(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode* cur = head;
    ListNode* pre = nullptr;

    // 保证返回的事最后一个节点地址
    while (cur->next)
    {
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }   
    // 连接最后一个节点
    cur->next = pre;
    return cur;
}
