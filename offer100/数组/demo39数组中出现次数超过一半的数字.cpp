#include <bits/stdc++.h>

using namespace std;


int MoreThanHalfNum_Solution(vector<int>& numbers) 
{
// 思路1 哈希表   
/*
    vector<int> hash(10001,0);    
    for (size_t i = 0; i < numbers.size(); i++)
    {
        hash[numbers[i]]++;
        if(hash[numbers[i]] * 2 > numbers.size() )
            return numbers[i];
    }
    return 0;
*/

// 思路2: 排序 中间那个数的次数就大于一半
    sort(numbers.begin(), numbers.end());
    return numbers[numbers.size() / 2];
}

int main()
{
    vector<int> array{3,3,3,3,2,2,2};
    int res = MoreThanHalfNum_Solution(array);
    cout << res << endl;
    return 0;
}
