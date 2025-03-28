#include <bits/stdc++.h>

using namespace std;

class Base {
public:
    static void function() {
        cout << "This is the Base class function" << endl;
    }
};

class Derived
{
public:
    void function() {
        cout << "This is the Derived class function" << endl;
    }

    void callBaseFunction() {
        Base::function(); // 调用父类的同名函数
    }
};

int main()
{
    return 0;
}