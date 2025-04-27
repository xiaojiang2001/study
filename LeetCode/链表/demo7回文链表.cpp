#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路1：利用双向队列保存链表节点，判断是否回文
// 思路2：利用双指针找到链表的中间位置，然后将后半段反转，将后半段依次与前半段比较
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 后半部分的头节点为slow
    ListNode* pre = nullptr;
    ListNode* cur = slow;
    while (cur->next != nullptr)
    {
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    // 将后半段反转的链表与前半段依次比较
    while (cur && head) {
        if(cur->val != head->val)
            return false;
        cur = cur->next;
        head = head->next;
    }
    return true;
}
int main()
{

}