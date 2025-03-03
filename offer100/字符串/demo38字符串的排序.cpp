#include <bits/stdc++.h>

using namespace std;

vector<string> res;
string path;

void backtracking(string str, vector<bool> &used)
{
    if(path.size() == str.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if(i > 0 && str[i] == str[i-1] && used[i-1] == false)
            continue;
        // 遍历未访问过的节点
        if(used[i] == false){
            path.push_back(str[i]);
            used[i] = true;
            backtracking(str,used);
            path.pop_back();
            used[i] = false;
        }
    }
}

vector<string> Permutation(string str) 
{
    path.clear();
    res.clear();
    if(str == "")
        return res;
    // 首先把给str排序，让其相同的元素都挨在一起。
    sort(str.begin(), str.end());
    vector<bool> used(str.size(), false);
    backtracking(str, used);
    return res;
}

int main()
{
    string str = "aba";
    vector<string> res = Permutation(str);
    for (auto  subStr :res)
        cout << subStr << endl;
    return 0;
}