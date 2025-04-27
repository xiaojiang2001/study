#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};


ListNode* swapPairs(ListNode* head) {
    if(head == nullptr)
        return nullptr;

    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = head;
    ListNode* pre = dummyHead;
    dummyHead->next = head;
    while (cur && cur->next)
    {
        ListNode* temp = cur->next->next;
        pre->next = cur->next;
        pre->next->next = cur;
        cur->next = temp;
        pre = cur;
        cur = temp;
    }
    return dummyHead->next;
}


int main()
{

}