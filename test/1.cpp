#include <iostream>
#include <vector>

using namespace std;

// 数据结构
struct ListNode {
    int m_nkey;
    ListNode* m_pNext;
    ListNode(int val) {m_nkey = val; m_pNext = NULL;};
};

void buildLinkList(ListNode** pHead1, ListNode** pHead2) 
{
    // 输入
    int arrLen1, arrLen2, firstSameNum, firstSameIndex1, firstSameIndex2;
    vector<int> arr1, arr2;

    cin >> arrLen1;
    arr1.resize(arrLen1);
    for (int i = 0; i < arrLen1; i++)
        cin >> arr1[i];
    cin >> arrLen2;
    arr2.resize(arrLen2);
    for (int i = 0; i < arrLen2; i++)
        cin >> arr2[i];
    cin >> firstSameNum >> firstSameIndex1 >> firstSameIndex2;

    // 记录链表第一个交点
    ListNode* pJoint = NULL;

    ListNode* pTempHead1 = NULL;
    ListNode** pTempNext = &pTempHead1;
    for (int i = 0; i < arrLen1; i++) {
        *pTempNext = new ListNode(arr1[i]);
        if (i == firstSameIndex1)
            pJoint = *pTempNext;
        pTempNext = &(*pTempNext)->m_pNext;
    }

    ListNode* pTempHead2 = NULL;
    pTempNext = &pTempHead2;
    for (int i = 0; i < firstSameIndex2 - 1; i++) {
        *pTempNext = new ListNode(arr2[i]);
        pTempNext = &(*pTempNext)->m_pNext;
    }
    (*pTempNext)->m_pNext = pJoint; // 指向交点

    *pHead1 = pTempHead1;
    *pHead2 = pTempHead2;
}

int findJointVal(ListNode* pHead1, ListNode* pHead2) {
    // 两个指针沿两个链表走到尾节点后，重新从另一个链表头出发
    // 直到相遇
    if (pHead1 == NULL || pHead2 == NULL)
        return -1;
    
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while (p1 != p2) {
        if (p1) {
            p1 = p1->m_pNext;
        } else {
            p1 = pHead2;
        }

        if (p2) {
            p2 = p2->m_pNext;
        } else {
            p2 = pHead1;
        }
    }

    if (p1)
        return p1->m_nkey;
    else
        return -1; 
}

int main() {
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    buildLinkList(&l1, &l2);    // 传引用为了修改指针

    int ret = findJointVal(l1, l2);

    cout << ret << endl;

    cout << "O(m+n)" << endl;

    return 0;
}
