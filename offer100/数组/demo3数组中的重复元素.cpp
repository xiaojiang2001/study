#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int duplicate(vector<int>& numbers) 
{
    unordered_set<int> uset;        // 统计数字吃否出现过
    for (int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] < 0 || numbers[i] > 10000)
            return -1;
        if(uset.find(numbers[i]) == uset.end())
            uset.insert(numbers[i]);
        else
            return numbers[i];
    }
    return -1;
}

int main() 
{

    return 0;
}