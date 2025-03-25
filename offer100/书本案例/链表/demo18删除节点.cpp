#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int m_val;
    ListNode* m_pNext;
    ListNode(int x): m_val(x), m_pNext(nullptr) {}
};

// 保证传入的节点在链表中
void DeleteNode(ListNode** head, ListNode* deleteNode)
{
    if(!head || !*head)
        return;
    
    // 删除非最后一个节点
    if(deleteNode->m_pNext != nullptr)
    {
        ListNode* deleteNext = deleteNode->m_pNext;

        deleteNode->m_val   = deleteNext->m_val;
        deleteNode->m_pNext = deleteNext->m_pNext;

        delete deleteNext;
        deleteNext = nullptr;
    }    

    // 只有一个节点(删除第一个/最后一个)
    else if(*head == deleteNode)
    {
        delete deleteNode;
        deleteNode = nullptr;
        *head = nullptr;
    }

    // 删除最后一个节点
    else
    {
        ListNode* cur = *head;
        while (cur->m_pNext != deleteNode){
            cur = cur->m_pNext;
        }
        // 找到了要删除的尾节点
        cur->m_pNext = nullptr;
        delete deleteNode;
        deleteNode = nullptr;
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
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    // node1->m_pNext = node2;
    // node2->m_pNext = node3;
    // node3->m_pNext = node4;
    // node4->m_pNext = node5;

    DeleteNode(&node1, node1);
    printLink(&node1);
}