#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x),next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

vector<int> printListFromTailToHead(ListNode* head) 
{
    vector<int> res;
    while (head)
    {
        res.push_back(head->val);
        head = head->next;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    return 0;
}