#include <bits/stdc++.h>

using namespace std;


vector<string> res;
string path;

void backtracking(string& str, int startIdx, vector<bool> used)
{
    if(path.size() == str.size()) {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if(used[i] == true)
            continue;
        if(str[i] == str[i-1] && used[i-1] == false)
            continue;
        
        used[i] = true;
        path += str[i];
        backtracking(str, startIdx + 1, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<string> Permutation(string str) {
    path.clear();
    res.clear();
    sort(str.begin(), str.end());
    vector<bool> used(str.size(), false);
    backtracking(str, 0, used);
    return res;
}


int main()
{
    string str = "aab";
    vector<string> res = Permutation(str);
    for (auto str :  res) {
        for (auto ch :  str) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}