#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int m_val;
    ListNode* m_pNext;
    ListNode(int x): m_val(x), m_pNext(nullptr) {}
};

ListNode* buildList(vector<int>& vec)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    for (int  i = 0; i < vec.size(); i++)
    {
        cur->m_pNext = new ListNode(vec[i]);
        cur = cur->m_pNext;
    }
    ListNode* head = dummyHead->m_pNext;
    delete dummyHead; 
    return head;
}

void printList(ListNode* root)
{
    if(root == nullptr)
        return;
    ListNode* cur = root;
    while (cur)
    {
        cout << cur->m_val << " ";
        cur = cur->m_pNext;
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {1,4,2,5,8,3,9};
    ListNode* root = buildList(vec);
    printList(root);
}