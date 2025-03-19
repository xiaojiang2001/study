#include <bits/stdc++.h>

using namespace std;

// 排序规则
bool cmp(string &x, string &y)
{
    return x + y < y + x;
}

string PrintMinNumber(vector<int>& numbers) 
{
    if(numbers.size() == 0)
        return "";
    vector<string> vec;
    // 数字存字符串入容器
    for (auto num : numbers) {
        vec.push_back(to_string(num));
    }
    sort(vec.begin(), vec.end(), cmp);
    //拼接结果
    string res = "";
    for (auto str : vec)
        res += str;
    
    return res;
}

int main()
{
    vector<int> numbers{3, 32, 321};
    string res = PrintMinNumber(numbers);
    cout << res << endl;
    return 0;
}