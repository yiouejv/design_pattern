#include<iostream>
using namespace std;

class SubSystemOne {
public:
    void Method1() {
        cout << "subSystemOne Method1" << endl;
    }
};

class SubSystemTwo {
public:
    void Method2() {
        cout << "subSystemTwo Method2" << endl;
    }
};

class SubSystemThree {
public:
    void Method3() {
        cout << "subSystemThree Method3" << endl;
    }
};

class Facade {
private:
    SubSystemOne subSys1;
    SubSystemTwo subSys2;
    SubSystemThree subSys3;
public:
    void MethodA() {
        subSys1.Method1();
        subSys3.Method3();
    }

    void MethodB() {
        subSys2.Method2();
    }
};


int main(int argc, char const *argv[])
{
    Facade fac;
    fac.MethodA();
    fac.MethodB();
    return 0;
}


