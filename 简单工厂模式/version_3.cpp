#include<iostream>
using namespace std;

class Calc {
public:
    static double calc(double num1, double num2, const char op) {
        if (op == '+') {
            return num1 + num2;

        }
        else if (op == '-') {
            return num1 - num2;

        }
        else if (op == '*') {
            return num1 * num2;

        }
        else if (op == '/') {
            if (num2 == 0) {
                cout << "除数不能为0！" << endl;
                return 0;
            }
            return num1 / num2;
        } else {
            throw;            
        }
    }
};


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

    result = Calc::calc(num1, num2, op);

    cout << "两个数的运算结果为: " << result << endl;
    return 0;
}
