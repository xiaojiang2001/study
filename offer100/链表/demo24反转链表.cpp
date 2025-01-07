#include <bits/stdc++.h>

using namespace std;    

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr) {}
};

ListNode* ReverseList(ListNode* head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur)
    {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;  
    }
    return pre;
}

ListNode* init_link(vector<int> &vec)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *cur =  dummyHead;
    for (size_t i = 0; i < vec.size(); i++)
    {
        ListNode *node = new ListNode(vec[i]);
        cur->next = node;
        cur = node;
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
    vector<int> vec{1,2,3,4,5};
    ListNode* head = init_link(vec);
    show_link(head);
    ListNode *res = ReverseList(head);
    show_link(res);
    return 0;
}