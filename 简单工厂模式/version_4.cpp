#include<iostream>
using namespace std;

class Calc {
public:
    virtual double calc(double num1, double num2) {
        return 0;
    };
};

class AddCalc : public Calc {
public:
    double calc(double num1, double num2) override {
        return num1 + num2;
    }
};

class SubCalc : public Calc {
public:
    double calc(double num1, double num2) override {
        return num1 - num2;
    }
};

class MulCalc : public Calc {
public:
    double calc(double num1, double num2) override {
        return num1 * num2;
    }
};

class DivCalc : public Calc {
public:
    double calc(double num1, double num2) override {
        if (num2 == 0) {
            cout << "除数不能为0！" << endl;
            return 0;
        }
        return num1 / num2;
    }
};

class CalcFactory {
public:
    static Calc* CreateCalc(const char op) {
        if (op == '+') {
            return new AddCalc;

        }
        else if (op == '-') {
            return new SubCalc;

        }
        else if (op == '*') {
            return new MulCalc;

        }
        else if (op == '/') {
            return new DivCalc;
        }
        else {
            throw;
        }
    }
};


int main(int argc, char const* argv[])
{
    char op;
    Calc *calc;
    double num1, num2, result;
    cout << "请输入数字A: " << endl;
    cin >> num1;

    cout << "请输入运算符(+, -, *, /):" << endl;
    cin >> op;

    cout << "请输入数字B: " << endl;
    cin >> num2;

    calc = CalcFactory::CreateCalc(op);
    result = calc->calc(num1, num2);

    cout << "两个数的运算结果为: " << result << endl;
    return 0;
}
