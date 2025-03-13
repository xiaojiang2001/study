#include <bits/stdc++.h>

using namespace std;


int NumberOf1Between1AndN_Solution(int n) {
    if(n == 0)
        return 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int bits = to_string(n).length();       // 数字
        switch (bits)
        {
            case 1: {
                if(i % 10 == 1) res++;  break;
            }
            case 2:{
                if(i / 10 == 1) res++;
                if(i % 10 == 1) res++;
                break;
            }
            case 3:{
                if(i / 100 == 1)        res++;
                if(i % 100 / 10 == 1)   res++;
                if(i % 10 == 1)         res++;
                break;
            }
            case 4:{
                if(i / 1000 == 11)      res++;
                if(i % 1000 / 100 == 1) res++;
                if(i % 100 / 10 == 1)   res++;
                if(i % 10 == 1)         res++;
                break;
            }
            case 5:{
                if(i / 10000 == 1)          res++;
                if(i % 10000 / 1000 == 1)   res++;
                if(i % 1000 / 100 == 1)     res++;
                if(i % 100 / 10 == 1)       res++;
                if(i % 10 == 1)             res++;
                break;
            }
        default:
            break;
        }
    }
    return res;
}


int main()
{

}