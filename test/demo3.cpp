#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& array, int left, int right)
{
	int pivot = left + (right - left) / 2;
	swap(array[pivot], array[right]);
	
	int idx = left;
	for (int i = left; i < right; i++)
	{
		if(array[i] < array[right]) {
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
	if(left == right)   
		return array[left];
	
	int pivot = partition(array, left, right);
	if(pivot == k)
		return array[pivot];
	else if(k < pivot)
		return quickSelect(array, left, pivot - 1, k);
	else
		return quickSelect(array, pivot + 1, right, k);
}

// 计算一个子数组是否满足条件
bool judgeSubArray(vector<int>& array)
{
	if (array.size() < 1 || array.size() % 2 == 0)
		return false;
	// 一定是奇个数
	int midVal = quickSelect(array, 0, array.size() -1 , array.size() / 2);     
	int midIdx = array.size() / 2;  // 中间位置
	if (array[midIdx] == midVal)
		return true;
	return false;
}

void pintf(vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int countArrayRes(vector<int>& array)
{
	int res = 0;
	
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = i; j < array.size(); j++)
		{
			vector<int> subArray(array.begin() + i, array.begin() + j + 1);
			bool flag = judgeSubArray(subArray);
			if(subArray.size() % 2 == 1 && flag) {
			 	res++;
			}
		}
	}
    return res;
}
// 算法二：给T组数字，每组数字作为一个数组，求每个数组的满足条件的连续子数组个数，条件：子数组中中间位置的元素刚好是子数组的中位数。
int main()
{
	int T;
	cin >> T;
	while(T--)
    {
		int N;
		cin >> N;
		vector<int> vec(N);
		for(int i = 0; i < N; i++) {
			cin >> vec[i];
		}
		int ret = countArrayRes(vec);
		cout << ret << endl;
	}
	return 0;
}