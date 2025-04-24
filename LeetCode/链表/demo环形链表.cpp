#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;

    // 找到交点
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            break;
    }
    // 无环
    if(fast == nullptr || fast->next == nullptr)
        return nullptr;
    
    // 双指针移动到交点
    ListNode* p1 = head;
    ListNode* p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p1;
}