#include <bits/stdc++.h>

using namespace std;

vector<int> printNumbers(int n) 
{
    int maxVal = 0;
    while (n) {
        maxVal = maxVal * 10 + 9;
        n--;
    }

    vector<int> vec(maxVal, 0);

    for(int i = 0; i < maxVal; i++)
        vec[i] = i + 1;
    
    return vec;
}


int main()
{
    int n;
    cin >> n;

    vector<int> vec = printNumbers(n);

    for (auto item : vec)
        cout << item << " ";

    return 0;
}
