#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x), next(nullptr) {}
};




// 思路1: 递归
ListNode* merge(ListNode* list1, ListNode* list2)
{
    if(list1 == nullptr)
        return list2;
    if(list2 == nullptr)
        return list1;
    
    ListNode* head = nullptr;

    if(list1->val < list2->val) {
        head = list1;
        list1->next = merge(list1->next, list2);
    }
    else{
        head = list2;
        list2->next = merge(list1, list2->next);
    }
    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = merge(list1, list2);
    return head;
}

// 非递归，模拟
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr)
        return list2;
    if(list2 == nullptr)
        return list1;

    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;

    while (cur1 && cur2)
    {
        if(cur1->val < cur2->val) {
            cur->next = cur1;
            cur = cur->next;
            cur1 = cur1->next;
        }
        else {
            cur->next = cur2;
            cur = cur->next;
            cur2 = cur2->next;
        }
    }
    
    while (cur1) {
        cur->next = cur1;
        cur = cur->next;
        cur1 = cur1->next;
    }
    while (cur2) {
        cur->next = cur2;
        cur = cur->next;
        cur2 = cur2->next;
    }

    return dummyHead->next;
}

int main()
{

}