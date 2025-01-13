#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* init_link(vector<int> &vec)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    for (auto num : vec) {
        ListNode* node = new ListNode(num);
        cur->next = node;
        cur = node;
    }
    return dummyHead->next;    
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) 
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    while (pHead1 && pHead2)
    {
        if(pHead1->val < pHead2->val) {
            ListNode* node = new ListNode(pHead1->val);
            cur->next = node;
            cur = node;
            pHead1 = pHead1->next;
        }
        else {
            ListNode* node = new ListNode(pHead2->val);
            cur->next = node;
            cur = node;
            pHead2 = pHead2->next;
        }
    }
    while (pHead1) {
        ListNode* node = new ListNode(pHead1->val);
        cur->next = node;
        cur = node;
        pHead1 = pHead1->next;
    }
    while (pHead2) {
        ListNode* node = new ListNode(pHead2->val);
        cur->next = node;
        cur = node;
        pHead2 = pHead2->next;
    }
    return dummyHead->next;
}

void show_link(ListNode* head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> nums1{1,3,5};
    vector<int> nums2{2,4,6};
    ListNode* link1 = init_link(nums1);
    ListNode* link2 = init_link(nums2);
    ListNode*  res = Merge(link1, link2);
    show_link(res);
    return 0;
}