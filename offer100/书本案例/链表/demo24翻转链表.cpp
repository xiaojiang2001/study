#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int m_val;
    ListNode* m_pNext;
    ListNode(): m_val(0), m_pNext(nullptr) {}
    ListNode(int val): m_val(val), m_pNext(nullptr) {}
};

ListNode* reverseLink(ListNode* head)
{
    if(head == nullptr)
        return nullptr;
    
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* reverseHead = nullptr;

    while (cur != nullptr)
    {
        // 最后一个节点了
        if(cur->m_pNext == nullptr) {
            cur->m_pNext = pre;
            reverseHead = cur;
            return reverseHead;
        }

        ListNode* temp = cur->m_pNext;

        cur->m_pNext = pre;

        pre = cur;
        cur = temp;
    }
    return reverseHead;
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
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node4->m_pNext = node5;

    ListNode* head = reverseLink(node1);
    printLink(head);

    return 0;

}