#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int m_val;
    ListNode* m_pNext;
    ListNode(int x): m_val(x), m_pNext(nullptr) {}
};

// 删除排序链表的重复节点
void DeleteNode(ListNode** head)
{
    if(!head || !*head)
        return;
    ListNode* cur = *head;
    ListNode* pre = nullptr;

    while (cur != nullptr)
    {
        ListNode* pNext = cur->m_pNext;
        bool needDelete = false;
        // 判断下个节点是否重复
        if(pNext != nullptr && cur->m_val == pNext->m_val)
            needDelete = true;

        // 不重复
        if(!needDelete) {
            pre = cur;
            cur = pNext;
        }
        //重复了 
        else {
            int val = cur->m_val;
            // pNext->m_val == cur->m_val || pNext == null
            while(pNext != nullptr && pNext->m_val == val) {
                ListNode* temp = cur;
                cur = pNext;
                pNext = pNext->m_pNext;

                delete temp;
                temp = nullptr;
            }

            // 结束了
            if(pNext == nullptr) {
                pre->m_pNext = pNext;
            }
            
            //不重复了
            else {
                pre->m_pNext = pNext;
                cur = pNext;
            }    
        }
    }
}

void printLink(ListNode** head)
{
    if(!head || !*head)
        return;

    ListNode* node = *head;

    while (node != nullptr)
    {
        cout <<  node->m_val << " ";
        node = node->m_pNext;
    }
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(4);
    ListNode* node7 = new ListNode(4);
    ListNode* node8 = new ListNode(5);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node4->m_pNext = node5;
    node5->m_pNext = node6;
    node6->m_pNext = node7;
    node7->m_pNext = node8;

    DeleteNode(&node1);
    printLink(&node1);
}