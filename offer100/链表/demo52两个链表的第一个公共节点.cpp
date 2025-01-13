#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
{
    int len1 = 0;
    int len2 = 0;
    ListNode* cur = pHead1;
    // 统计两根链表的长度
    while (cur) {
        len1++;
        cur = cur->next;
    }
    cur = pHead2;
    while (cur) {
        len2++;
        cur = cur->next;
    }
    // 保证link1>link2
    if(len1 < len2){
        swap(pHead1, pHead2);
        swap(len1, len2);
    }
    int offset = len1 - len2;
    // 便宜link1, 保证尾对齐
    ListNode* cur1 = pHead1;
    ListNode* cur2 = pHead2;
    while (offset)
    {
        cur1 = cur1->next;
        offset--;
    }
    while (cur1 && cur2)
    {
        if(cur1 == cur2)
            return cur1;
        else {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    return nullptr;
}

int main()
{



    return 0;
}