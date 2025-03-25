#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int m_val;
    ListNode* m_pNext;
    ListNode(int x):m_val(x), m_pNext(nullptr){}
};

ListNode* TopKfromTail(ListNode* pHead, int k)
{
    // 参数检查
    if(pHead == nullptr || k <= 0)
        return nullptr;

    ListNode* fast = pHead;
    ListNode* slow = pHead;
    // 移动快指针k-1步
    for (int i = 0; i < k-1; i++) {
        fast = fast->m_pNext;
        // K > length
        if(fast == nullptr)
            return nullptr;
    }
    
    // 把快指针移到尾节点
    while (fast->m_pNext != nullptr)
    {
        fast = fast->m_pNext;
        slow = slow->m_pNext;
    }

    return slow;
}


void showLink(ListNode* pHead)
{
    if(pHead == nullptr)
        return;
    
    ListNode* cur = pHead;
    while (cur != nullptr) {
        cout << cur->m_val << " ";
        cur = cur->m_pNext;
    }
    cout << endl;

    return;
}


int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node4->m_pNext = node5;

    // test
    int k = 3;              // test: -1 0 1 3 9
    ListNode* resHead = TopKfromTail(node1, k);
    showLink(resHead);

    //  test null 
    // ListNode* head2 = TopKfromTail(nullptr, 3);
    // showLink(head2);

    return 0;
}