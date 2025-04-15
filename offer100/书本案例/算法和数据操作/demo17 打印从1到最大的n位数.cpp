#include <bits/stdc++.h>

using namespace std;

void  printNum(const char* number)
{
    if(number == nullptr)
        return;
    int len = strlen(number);
    int idx = 0;
    // 过滤0
    while (idx < len && number[idx] == 0){
        idx++;
    }
    // 打印数值
    for (int i = idx; i < len; i++) {
        cout << number[i];
    }
    cout << "\t";
}

bool increment(char* number)
{
    bool isOverflow = false;

    int overTake = 0;               // 进位标志
    int length = strlen(number);

    for (int i = length - 1; i >= 0; i--) 
    {
        int sum = number[i] - '0' + overTake;
        if(i == length - 1)     // 最后一位
            sum++;
        
        // 进位
        if(sum >= 10)
        {
            // 最高位 溢出
            if(i == 0)
                isOverflow = true;
            else{
                sum -= 10;
                overTake = 1;
                number[i] = '0' + sum;
            }
        }
        else
        {
            number[i] = '0' + sum;      // 更新当前位
            break;
        }
    }
    return isOverflow; // 返回是否溢出
}
void print1ToN(int n)
{
    if(n <= 0)
        return;
    
    char *number = new char[n + 1];
    memset(number , '\0', n);
    number[n] = '\0';

    bool isOverflow = false;
    while (!isOverflow)
    {
        isOverflow = increment(number);
        if(!isOverflow)
            printNum(number);
    }
    delete[] number;
}

int main()
{
    int n;
    cin >> n;
    print1ToN(n);
    return 0;
}