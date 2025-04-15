#include <bits/stdc++.h>

using namespace std;

// int NumberOf1(int n) 
// {
//     int cnt = 0;
//     unsigned int flag = 1;
//     while (flag)
//     {
//         if(n & flag)
//             cnt++;

//         flag  = flag << 1; 
//     }
//     return cnt;
// }


int NumberOf1(int n) 
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n = (n-1) & n;
    }
    return cnt;
}



int main()
{

}