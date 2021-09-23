#include<iostream>
using namespace std;

class Base {
public:
    virtual void Operation1() = 0;  
    virtual void Operation2() = 0;
    void TemplateMethod() {
        Operation1();
        Operation2();
    }
};

class Derived1 : public Base {
public:
    virtual void Operation1() override {
        cout << "Derived1 Operation1" << endl;
    }
    virtual void Operation2() override {
        cout << "Derived1 Operation2" << endl;
    }
};

class Derived2 : public Base {
public:
    virtual void Operation1() override {
        cout << "Derived2 Operation1" << endl;
    }
    virtual void Operation2() override {
        cout << "Derived2 Operation2" << endl;
    }
};


int main(int argc, char const *argv[])
{
    Derived1 d1;
    d1.TemplateMethod();

    Derived2 d2;
    d2.TemplateMethod();
    return 0;
}