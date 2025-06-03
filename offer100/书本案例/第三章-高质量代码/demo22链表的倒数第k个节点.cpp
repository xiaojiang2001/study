#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {}
};

ListNode* FindKthToTail(ListNode* root, int k)
{
    // 参数异常
    if(root == nullptr || k <= 0)
        return nullptr;
    ListNode* slow = root;
    ListNode* fast = root;

    // 慢指针先移动K步
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
        if(fast == nullptr) {
            // k大于len
            if(i < k-1)
                return nullptr;
            break;
        }
    }
    
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* init_link(vector<int>& vec)
{
    if(vec.empty())
        return nullptr;
    ListNode* root = new ListNode(vec[0]);
    ListNode* cur = root;
    for (int i = 1; i < vec.size(); i++)
    {
        ListNode* node = new ListNode(vec[i]);
        cur->next = node;
        cur = cur->next;
    }
    return root;
}

void delete_link(ListNode* root)
{
    while (root != nullptr)
    {
        ListNode* temp = root;
        root = root->next;
        delete temp;
    }
}


void show_link(ListNode* root)
{
    ListNode* ptr = root;
    while (ptr != nullptr) {
        cout << ptr->val;
        cout << " "; 
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    vector<int> vec{1,2,3};
    int k = 0;
    ListNode* root = init_link(vec);
    ListNode* ansPtr = FindKthToTail(root, 4);
    show_link(ansPtr);
    delete_link(root);
    return 0;
}