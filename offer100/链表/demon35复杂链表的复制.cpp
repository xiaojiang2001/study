#include <bits/stdc++.h>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


RandomListNode* Clone(RandomListNode* pHead) {
    if(pHead == nullptr)
        return nullptr;

    RandomListNode* dummyHead = new RandomListNode(0);      // 虚拟头节点
    unordered_map<RandomListNode*, RandomListNode*> umap;   // 建立新旧节点映射
    RandomListNode* pre = dummyHead;
    RandomListNode* cur = pHead;
    while (cur)
    {
        // 创建新节点
        RandomListNode* clone = new RandomListNode(cur->label);
        pre->next = clone;      // 链接
        umap[cur] = clone;      // 映射
        cur = cur->next ;
        pre = pre -> next;
    }

    // 遍历map, 查看旧节点是否有randow
    for (auto& [key, val] : umap) {
        if(key->random)
            val->random = umap[key->random];
    }
    delete dummyHead;
    return umap[pHead];
}


int main()
{

}