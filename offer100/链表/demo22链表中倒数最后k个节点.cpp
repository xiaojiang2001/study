#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* FindKthToTail(ListNode* pHead, int k) 
{
    ListNode *cur = pHead;
    // 统计链表的长度
    int len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
    cur = pHead;
    int idx = len - k;  // 记录起始点
    if(idx < 0)
        return nullptr;

    int cnt = 0;        // 记录遍历过的点
    // 初始化结果的虚拟头节点
    ListNode *dummyHead = new ListNode(0);
    while (cur)
    {
        if(cnt >= idx) {
            dummyHead->next = cur;
            break;
        }
        cnt++;
        cur = cur->next;
    }
    return dummyHead->next;
}

ListNode *init_link(vector<int> &vec)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *cur = dummyHead;
    for (int i = 0; i < vec.size(); i++)
    {
        ListNode *node = new ListNode(vec[i]);
        cur->next = node;
        cur = node;
    }
    return dummyHead->next;
}
void show_link(ListNode *head)
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
    vector<int> nums{0,2,3,4,5};
    int k = 5;
    ListNode *head = init_link(nums);
    show_link(head);
    ListNode *res =  FindKthToTail(head, k);
    show_link(res);
    return 0;
}