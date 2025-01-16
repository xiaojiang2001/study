#include <bits/stdc++.h>

using namespace std;

vector<int> multiply(vector<int>& A) 
{
    vector<int> B(A.size(), 1);
    // 左下角 
    //每多一位由数组B左边的元素多乘一个前面A的元素
    for (int i = 1; i < A.size(); i++) 
        B[i] = B[i-1] * A[i-1];
    
    int temp = 1;   // temp为右边的累乘
    for (int i = A.size() - 1; i >= 0; i--){
        B[i] *= temp; 
        temp *= A[i];
    }
    return B;
}


int main()
{

    return 0;
}