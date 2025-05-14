#include <bits/stdc++.h>

using namespace std;

// 时间负责度O(n), 空间负责度O(n)
vector<int> sockCollocation(vector<int>& sockets) {
    vector<int> res;
    unordered_set<int> uset;
    for (int i = 0; i < sockets.size(); i++)
    {
        
        // 配对 移除之前的
        if(uset.find(sockets[i]) != uset.end())
            uset.erase(sockets[i]);
        else
            uset.insert(sockets[i]);
    }

    for (auto num : uset)  {
        res.push_back(num);
    }
    return res;
}


// 时间复杂度O(n), 空间复杂度O(1)
vector<int> sockCollocation(vector<int>& sockets) {
    vector<int> res(2, 0);
    // 异或和 r = a ^ b 
    // a != b  等价于 a的二进制与b的二进制的异或和二进制r至少有一位位1


    int xorResult = 0;         
    // 将所有数字进行亦或处理，由于其他数字都出现两次，异或后会相互抵消
    // 最终 xorResult 的值是两个只出现一次的数字的异或结果
    // 第一步：将所有数字进行异或处理
    for(auto num : sockets)
        xorResult ^= num;
    
    // 第二步：找到异或结果中任意一个为1的位
    int diffbits = xorResult & (-xorResult);    

    // 第三步：根据这个位将数组分成两组，并分别进行异或操作
    for(auto num : sockets) {
        if(num & diffbits)
            res[0] ^= num;
        else
            res[1] ^= num;
    }
    return res;
}