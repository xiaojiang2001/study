#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int m_val;
    ListNode* m_pNext;
    ListNode():m_val(0), m_pNext(nullptr) {}
    ListNode(int val):m_val(val), m_pNext(nullptr) {}
};

ListNode* circleEnter(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;

    ListNode* fast = pHead;     // 快指针 2步
    ListNode* slow = pHead;     // 慢指针 1步
    while (fast != nullptr && fast->m_pNext != nullptr)
    {
        slow = slow->m_pNext;
        fast = fast->m_pNext->m_pNext;
        // 成环
        if(fast == slow)
        {
            // temp从起点出发 和slow汇合
            ListNode* temp = pHead;
            while (temp != slow) {
                slow = slow->m_pNext;
                temp = temp->m_pNext;
            }
            // 汇合了 找到入口
            return slow;
        }
    }   
    // 没有环
    return  nullptr;
    
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
        // 重复入环了 不重复打印了
        if(cur == pHead) {
            cout << endl << "上述节点成环";
            break;
        }
           
    }
    cout << endl;
    return;
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

    ListNode* resHead = nullptr;

    // // 无环
    // resHead = circleEnter(node1);
    // printLink(resHead);

    // 测试环
    node5->m_pNext = node3;
    resHead = circleEnter(node1);
    printLink(resHead);

    // // 一个节点 取消node1-node5的链接 开启下面
    // node1->m_pNext = node1;    // 1个节点成环
    // resHead = circleEnter(node1);
    // printLink(resHead);

    return 0;
}