#include<iostream>
using namespace std;


int main(int argc, char const* argv[])
{
    char op;
    double num1, num2, result;
    cout << "请输入数字A: " << endl;
    cin >> num1;

    cout << "请输入运算符(+, -, *, /):" << endl;
    cin >> op;

    cout << "请输入数字B: " << endl;
    cin >> num2;

    if (op == '+') {
        result = num1 + num2;

    } else if (op == '-') {
        result = num1 - num2;

    } else if (op == '*') {
        result = num1 * num2;

    } else if (op == '/') {
        if (num2 == 0) {
            cout << "除数不能为0！" << endl;
            return 0;
        }
        result = num1 / num2;
    }

    cout << "两个数的运算结果为: " << result << endl;
    return 0;
}
