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
    virtual Calc* CreateCalc() {
        return new Calc;
    }
};

class AddCalcFactory : public CalcFactory {
public:
    virtual Calc* CreateCalc() {
        return new AddCalc;
    }
};

class SubCalcFactory : public CalcFactory {
public:
    virtual Calc* CreateCalc() {
        return new SubCalc;
    }
};

class MulCalcFactory : public CalcFactory {
public:
    virtual Calc* CreateCalc() {
        return new MulCalc;
    }
};

class DivCalcFactory : public CalcFactory {
public:
    virtual Calc* CreateCalc() {
        return new DivCalc;
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

    CalcFactory *factory;
    if (op == '+') {
        factory = new AddCalcFactory;

    }
    else if (op == '-') {
        factory = new SubCalcFactory;

    }
    else if (op == '*') {
        factory = new MulCalcFactory;

    }
    else if (op == '/') {
        factory = new DivCalcFactory;
    }
    else {
        throw;
    }

    calc = factory->CreateCalc();
    result = calc->calc(num1, num2);
    cout << "两个数的运算结果为: " << result << endl;
    delete calc;
    return 0;
}