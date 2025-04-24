#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路1：快慢指针，快指针到尾，慢指针到中间节点
ListNode* middleNode(ListNode* head) 
{
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}