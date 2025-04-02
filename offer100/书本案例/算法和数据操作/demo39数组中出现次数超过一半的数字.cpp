#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& vec, int left, int right)
{
    int pivot = left + (right - left) / 2;
    int pivotVal = vec[pivot];

    swap(vec[pivot], vec[right]);

    int idx = left;
    for (int i = left; i < right; i++)
    {
        if(vec[i] < pivotVal) {
            swap(vec[i], vec[idx]);
            idx++;
        }
    }
    
    swap(vec[right], vec[idx]);
    return idx;
}


bool CheckMoreThanHalf(vector<int>& numbers, int num)
{
    int times = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if(num == numbers[i])
            times++;
    }
    if(2 * times <= numbers.size())
        return false;
    
    return true;
}

int MoreThanHalfNum_Solution(vector<int>& numbers) 
{
    if(numbers.empty())
        return -1;
    int mid = numbers.size() / 2;
    int left = 0;
    int right = numbers.size() - 1;
    int pivot = partition(numbers, left, right);
    while (pivot != mid)
    {
        if(pivot < mid) {
            left = pivot + 1;
            pivot = partition(numbers, left, right);
        }
        else
        {
            right = pivot -1;
            pivot = partition(numbers, left, right);
        }
    }
    int res = numbers[pivot];
    if(CheckMoreThanHalf(numbers, res) == true)
        return res;
    
    return -1;
}

int MoreThanHalfNum_Solution(vector<int>& numbers)
{
    if(numbers.empty())
        return -1;
    
    int length = numbers.size();
    int result = numbers[0];
    int cnt  = 1;

    for (int i = 1; i < numbers.size(); i++)
    {
        if(cnt == 0) {
            result = numbers[i];
            cnt = 1;
        }
        if(numbers[i] == result) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    if(CheckMoreThanHalf(numbers, result))
        return result;
    
    return -1;
}




int main()
{
    return 0;
}