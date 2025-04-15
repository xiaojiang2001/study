#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& vec, int left, int right) 
{
    if (vec.empty() || left < 0 || right >= vec.size())
        return -1;

    int pivot = left + rand() % (right - left + 1) / 2;
    swap(vec[pivot], vec[right]);

    int idx = left;
    for (int i = left; i < right; i++) {
        if (vec[i] < vec[right]) {
            swap(vec[i], vec[idx]);
            idx++;
        }
    }

    swap(vec[right], vec[idx]);
    return idx;
}

vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) 
{
    if (input.empty() || k <= 0)
        return vector<int> {};
    if (k >= input.size())
        return input;
    int left = 0;
    int right = input.size() - 1;
    int pivot = partition(input, left, right);
    while (pivot != k - 1) {
        if (pivot < k) {
            pivot = partition(input, pivot + 1, right);
        } else
            pivot = partition(input, left, pivot - 1);
    }
    vector<int> res(input.begin(), input.begin() + k);
    return res;
}
void print(const vector<int>& vec)
{
    for (auto num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // vector<int> vec = {4,5,1,6,2,7,3,8};
    vector<int> vec = {234,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233,233};
    int k = 10;
    vector<int> res = GetLeastNumbers_Solution(vec,k);
    print(res);
    return 0;
}