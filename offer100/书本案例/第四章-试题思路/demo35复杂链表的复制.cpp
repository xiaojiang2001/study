#include <bits/stdc++.h>

using namespace std;

struct RandomListNode{
    int label;
    RandomListNode* next;
    RandomListNode* random;
    RandomListNode(int x):label(x),next(nullptr),random(nullptr) {}
};

RandomListNode* Clone(RandomListNode* pHead) {
    if(pHead == nullptr)
        return nullptr;

    RandomListNode* cur = pHead;
    unordered_map<RandomListNode*, RandomListNode*> umap;

    
    // 构造链表虚拟头节点
    RandomListNode* dummyHead = new RandomListNode(-1);
    RandomListNode* pre = dummyHead;
    cur = pHead;
    // 复制链表 
    while (cur != nullptr)
    {
        RandomListNode* node = new RandomListNode(cur->label);
        pre->next = node;



        pre = pre->next;
        cur = cur->next;
    }

    // 清除虚拟头节点内存
    RandomListNode* root = dummyHead->next;
    delete dummyHead;
    return root;
}

int main()
{

}