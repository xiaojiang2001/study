#include <bits/stdc++.h>

using namespace std;

int MoreThanHalfNum_Solution(vector<int>& numbers)
{
    sort(numbers.begin(), numbers.end());
    // number[i] = number[i + number.size() / 2];
    for (int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == numbers[i + numbers.size() / 2])
            return numbers[i];
    }
    return -1;
}



int main()
{

}