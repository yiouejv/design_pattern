#include<iostream>
using namespace std;


int main(int argc, char const* argv[])
{
    char b;
    double a, c, d;
    cout << "请输入数字A: " << endl;
    cin >> a;

    cout << "请输入运算符(+, -, *, /):" << endl;
    cin >> b;

    cout << "请输入数字B: " << endl;
    cin >> c;

    if (b == '+') {
        d = a + c;
    }

    if (b == '-') {
        d = a - c;
    }

    if (b == '*') {
        d = a * c;
    }
    if (b == '/') {
        d = a / c;
    }

    cout << "两个数的运算结果为: " << d << endl;
    return 0;
}
