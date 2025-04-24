#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路1: 利用哈希标记元素是否出现过，若出现过，则删除 时间复杂度为O(1) 空间复杂度O(n)
// 思路2：利用双指针的偏移,判断当前元素在后面出现了就删除, 时间复杂度为O(n^2), 空间复杂度为O(1)
ListNode* removeDuplicateNodes(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;

    unordered_map<int, int> umap;
    ListNode* cur = head;
    umap.insert({cur->val, 1});

    while (cur->next)
    {
        // 重复
        if(umap.find(cur->next->val) != umap.end())
        {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else{
            umap.insert({cur->next->val, 1});
            cur = cur->next;
        }
            
    }
    return head;
}

ListNode* removeDuplicateNodes(ListNode* head) 
{
    if(head == nullptr || head->next == nullptr)
        return head;
    
    ListNode* p = head;

    while (p)
    {
        ListNode* cur = p;
        while (cur->next)
        {
            // 重复
            if(cur->next->val == p->val){
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
                cur = cur->next;
        }
        p = p ->next;
    }
    
    return head;
}

ListNode* init_link(vector<int> vec)
{
    if(vec.size() == 0)
        return nullptr;
    
    ListNode* head = new ListNode(vec[0]);
    ListNode* cur = head;

    for (int i = 1; i < vec.size(); i++) {
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }
    return head;
}

int main()
{
    
}