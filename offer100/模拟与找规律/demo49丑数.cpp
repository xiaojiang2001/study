#include <bits/stdc++.h>

using namespace std;


int GetUglyNumber_Solution(int index) {
    vector<int> array{2, 3, 5};
    int idx = 1;
    if(index == 1)
        return 1;

    while (1)
    {
        idx++;
        auto minIdx = min_element(array.begin(), array.end());
        // 下个丑数不能直接乘以2
        if(idx == index)
            return *minIdx;
        else
            *minIdx = *minIdx * 2;
    }
    return -1;
}

int main()
{

    return 0;
}