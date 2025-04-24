#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路1：遍历一遍链表，计算len，求倒数k个元素，注意cnt的各种异常情况
// 思路2：快慢指针，快指针先走k步，随后一起走，快指针到尾巴，慢指针到结果值，注意各种异常情况

ListNode* trainingPlan(ListNode* head, int cnt) {
    if(head == nullptr || cnt <= 0)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (cnt-- && fast) {
        fast = fast->next;
    }
    if(fast == nullptr)
        return head;

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}