#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& array, int left, int right)
{
    int pivot = (right + left) / 2;
    int pival = array[pivot];

    swap(array[pivot], array[right]);

    int idx = left;
    for (int i = left; i < right; i++)
    {
        if(array[i] < pival) {
            swap(array[i], array[idx]);
            idx++;
        }
    }
    swap(array[right], array[idx]);
    return idx;
}


// 计算奇数个数组成的数组的中位数
int quickSelect(vector<int> &array, int left, int right, int k)
{
    if(left == right)   return array[left];
    int pivot = partition(array, left, right);
    if(k < left || k > right)
        return -1;

    int ret = 0;

    if(k == pivot)
        return array[k];
    else if(k < pivot){
        ret = quickSelect(array, left, pivot - 1, k);
        return ret;
    }
    else{
        ret = quickSelect(array, pivot + 1, right, k);
        return ret;
    }
}

int main()
{
    vector<int> array{1,4,7,9,10,5,8};
    int k = 5;
    int ret = quickSelect(array, 0, array.size() - 1, k-1);

    cout << ret << " " << endl;

    return 0;
}