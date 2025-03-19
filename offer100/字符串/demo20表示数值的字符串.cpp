#include <bits/stdc++.h>

using namespace std;


// 字符串以int开头
bool judgeInt(string str)
{


}
// 字符串以小数开头
bool judgeFloat(string str)
{
    if(str == "")
        return false;
    int i = 0;
    // 找到第一个位置非数字
    while (str[i] > '0' && str[i] < '9') {
        i++;
    }
    // 第一位非数字 || 数字后面跟着非.
    if(i == 0 || str[i] != '.') return false;
    i++;            //小数点   
    while (str[i] > '0' && str[i] < '9') {
        i++;
    }
}

bool isNumeric(string str) {
    int i = 0;
    int len = str.size();
    if(len == 0)
        return false;

    // 移除空格
    while (i < len && str[i] == ' ') {
        i++;
    }

    // 存在 +,'-'
    if(str[i] == '+' || str[i] == '-')
        i++;
    if(i >= len)
        return false; 
    str = str.substr(i);  

}

int main()
{
    return 0;
}