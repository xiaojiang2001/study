#include <bits/stdc++.h>

using namespace std;

bool IsContinuous(vector<int>& numbers) 
{
    // 统计0的个数
    int cnt0 = count(numbers.begin(), numbers.end(), 0);
    // 删除数组中的0
    for (auto  it = numbers.begin(); it < numbers.end(); ){
        if(*it == 0)
            numbers.erase(it);
        else
            it++;
    }
    // 判断是否有重复元素
    bool flag = false;
    int offset = 0;     // 记录偏差
    // 从小到大排序
    sort(numbers.begin(), numbers.end());
    for (size_t i = 1; i < numbers.size(); i++) {
        // 重复
        if(numbers[i] == numbers[i-1]){
            flag = true;
            break;
        }
        offset += numbers[i] - numbers[i-1];
    }

    if(flag || offset > 4)
        return false;
    else
        return true;
}


int main()
{

    return 0;
}