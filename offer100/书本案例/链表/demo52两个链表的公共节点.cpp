#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int m_val;
    ListNode* m_pNext;
    ListNode(): m_val(0), m_pNext(nullptr) {}
    ListNode(int val): m_val(val), m_pNext(nullptr) {}
};

ListNode* CommonNode(ListNode* pHead1, ListNode* pHead2)
{
    // 保证两个链表都有节点
    if(pHead1== nullptr || pHead2 == nullptr)
        return nullptr;

    int len1 = 0;
    int len2 = 0;
    ListNode* cur = pHead1;
    // 获取2个链表的长度
    while (cur != nullptr) {
        cur = cur->m_pNext;
        len1++;
    }
    cur = pHead2;
    while (cur != nullptr) {
        cur = cur->m_pNext;
        len2++;
    }

    // 保证len1 > len2
    if(len1 < len2) {
        swap(len1, len2);
        swap(pHead1, pHead2);
    }

    int offset = len1 - len2;
    ListNode* pNode1 = pHead1;
    ListNode* pNode2 = pHead2;
    // 两个尾对齐
    for (int i = 0; i < offset; i++){
        pNode1 = pNode1->m_pNext;
    }

    // 找公共节点
    while (pNode1 != nullptr && pNode2 != nullptr)
    {
        if(pNode1 == pNode2)
            return pNode1;

        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    // 无公共节点
    return nullptr;
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
    // 链表1
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node4->m_pNext = node5;

    // 链表2
    ListNode* node6 = new ListNode(6);
    node6->m_pNext = node3;


    ListNode* head = CommonNode(node1, node6);
    printLink(head);

    return 0;

}