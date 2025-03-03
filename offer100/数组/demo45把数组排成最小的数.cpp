#include <bits/stdc++.h>

using namespace std;

// 小顶堆
class cmp{
public:
    bool operator()(string str1, string str2)
    {
        if(str1.size() > str2.size()) {
            swap(str1, str2);
        }
        
    }
};

string PrintMinNumber(vector<int>& numbers) 
{
    if(numbers.size() == 0)
        return "";

    priority_queue<string, vector<string>, cmp> pri_que;
    //把字符串按大小排序放入小顶堆
    for (auto num : numbers) {
        pri_que.push(to_string(num));
    }
    
    //拼接结果
    string res = "";
    while (!pri_que.empty())
    {
        res += pri_que.top();
        pri_que.pop();
    }
    return res;
}

int main()
{
    vector<int> numbers{3, 32, 321};
    string res = PrintMinNumber(numbers);
    cout << res << endl;
}