#include <bits/stdc++.h>

using namespace std;



void  printNum(const char* number)
{

}


bool overflowNum(const char * number)
{
    bool overflow = false;
    int length = strlen(number);

    for (int i = length - 1; i >= 0; i--)
    {
        
    }
    
}


void print1ToN(int n)
{
    if(n <= 0)
        return;
    
    char *number = new char(n + 1);
    memset(number , '\0', n);
    number[n] = '\0';

    while (!overflowNum(number))
    {
        printNum(number);
    }

    delete[] number;
    
}