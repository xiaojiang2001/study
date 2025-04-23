#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#include "string.h"
  

int main()
{
    int a = 10;
    int b = 20;
    const int * p = &a;
    a = 20;
    cout << *p << endl;
}