#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x), next(nullptr) {}
};



// 思路1: 计算len1, len2, 保证len1 < len2, headA偏移len1 - len2, 一直遍历到尾巴
// 适合对链表长度进行预处理后再查找交点

// 思路2：通过双指针的方式，让两个指针分别从两个链表头开始遍历，当某个指针到达链表末尾时，将其指向另一个链表的头节点，继续遍历。
// 这样可以保证两个指针在第二次遍历中同步到达交点或链表末尾。 逻辑更为简洁，避免了显式计算链表长度的步骤，代码实现更紧凑。

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    if(headA == nullptr || headB == nullptr)
        return nullptr;

    int lenA = 0;
    int lenB = 0;

    // 计算链表长度
    ListNode* cur = headA;
    while (cur) {
        lenA++;
        cur = cur->next;
    }

    cur = headB;
    while (cur) {
        lenB++;
        cur = cur->next;
    }

    // 保证B更长
    if(lenA > lenB) {
        swap(lenA, lenB);
        swap(headA, headB);
    }

    // 链表B先偏移长度差值个单位
    int offset  = lenB - lenA;
    cur = headB;
    while (offset--) {
        cur = cur->next;
    }   

    // 获取交点
    ListNode* cur1 = headA;
    ListNode* cur2 = cur;
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    return cur1;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode* p = headA;
    ListNode* q = headB;

    while (p != q)
    {
        if(p == nullptr)
            p = headB;
        else
            p = p->next;

        if(q == nullptr)
            q = headA;
        else
            q = q->next;
    }
    return p;
}




int main()
{

}