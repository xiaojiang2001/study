#include <bits/stdc++.h>

using namespace std;

vector<string> res;
string path;

void backtracking(string str, int start, vector<bool> visited)
{
    if(path.size() == str.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = start; i < str.size(); i++)
    {
        path.push_back(str[i]);
        backtracking(str, start, visited);
        path.pop_back();
    }
}

vector<string> Permutation(string str) 
{
    vector<bool> visited(str.size(), false);
    backtracking(str, 0, visited);
    return res;
}

int main()
{
    string str = "abc";
    vector<string> res = Permutation(str);
    for (auto  subStr :res)
        cout << subStr << endl;
    return 0;
}