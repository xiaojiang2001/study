#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int m_val;
    ListNode* m_pNext;
    ListNode():m_val(0),m_pNext(nullptr){}
    ListNode(int val):m_val(val),m_pNext(nullptr){}
};


ListNode* mergeLink(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* dummyHead = new ListNode(-1);
    ListNode* tail = dummyHead;

    while (pHead1 && pHead2)
    {
        if(pHead1->m_val < pHead2->m_val) {
            tail->m_pNext = pHead1;
            pHead1 = pHead1->m_pNext;
        }
        else {
            tail->m_pNext = pHead2;
            pHead2 = pHead2->m_pNext;
        }
        tail = tail->m_pNext;
    }

    if (pHead1) {
        tail->m_pNext = pHead1;
    }
    if (pHead2) {
        tail->m_pNext = pHead2;
    }

    return dummyHead->m_pNext;
}


ListNode* sortLink(ListNode* pHhead)
{
    if(pHhead == nullptr || pHhead->m_pNext == nullptr)
        return pHhead;

    ListNode* slow = pHhead;
    ListNode* fast = pHhead->m_pNext;
    while (fast != nullptr && fast->m_pNext != nullptr)
    {
        slow = slow->m_pNext;
        fast = fast->m_pNext->m_pNext;
    }
    // 分割链表
    ListNode* left  = pHhead;
    ListNode* right = slow->m_pNext;
    slow->m_pNext = nullptr;

    left = sortLink(left);
    right = sortLink(right);

    return mergeLink(left, right);
}


void printLink(ListNode* pHead)
{
    if(pHead == nullptr)
        return;

    ListNode* cur = pHead;

    while (cur != nullptr)
    {
        cout << cur->m_val << " ";
        cur = cur->m_pNext;
    }
    cout << endl;
    return;
    
}

int main()
{
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(8);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(4);
    // node1->m_pNext = node2;
    // node2->m_pNext = node3;
    // node3->m_pNext = node4;
    // node4->m_pNext = node5;

    ListNode* resHead = sortLink(node1);
    printLink(resHead);

    
    return 0;
}