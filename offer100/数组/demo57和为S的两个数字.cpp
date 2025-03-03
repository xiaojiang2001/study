#include <bits/stdc++.h>

using namespace std;


vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    unordered_set<int> uset;
    // 数组入容器
    for(auto num : array)
        uset.insert(num);

    for (size_t i = 0; i < array.size(); i++)
    {
        if(uset.find(sum - array[i]) != uset.end())
            return vector<int> {array[i], sum - array[i]};
        else if(array[i] + array[i] == sum)
            return vector<int> {array[i], array[i]};
    }
    return vector<int>{};
}