#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if(pHead == nullptr)
        return nullptr;
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        // 相遇
        if(slow == fast) {
            ListNode* index1 = slow;
            ListNode* index2 = pHead;
            // 找环入口
            while (index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    return nullptr;
}

int main()
{

}