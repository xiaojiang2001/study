#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int m_val;
    ListNode* m_pNext;
    ListNode(): m_val(0), m_pNext(nullptr) {}
    ListNode(int val): m_val(val), m_pNext(nullptr) {}
};

ListNode* mergeLink(ListNode* pHead1, ListNode* pHead2)
{   
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;

    ListNode* mergeHead = nullptr;
    if(pHead1->m_val <= pHead2->m_val) {
        mergeHead = pHead1;
        mergeHead->m_pNext = mergeLink(pHead1->m_pNext, pHead2);
    }
    else {
        mergeHead = pHead2;
        mergeHead->m_pNext = mergeLink(pHead1, pHead2->m_pNext);
    }
    return mergeHead;
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
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(3);

    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(5);
    node1->m_pNext = node2;
    node2->m_pNext = node3;

    node4->m_pNext = node5;

    ListNode* head = mergeLink(node1, node4);
    printLink(head);

    return 0;

}