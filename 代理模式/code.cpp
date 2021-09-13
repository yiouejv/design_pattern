#include<iostream>
using namespace std;


class Subject {
public:
    virtual void Request() = 0;
};

class RealSubject : public Subject{
public:
    virtual void Request() {
        cout << "RealSubject Request" << endl;
    }
};

class Proxy : public Subject {
private:
    RealSubject *real = nullptr;
public:
    ~Proxy() {
        if (real) {
            delete real;
        }
    }
    virtual void Request() override {
        if (!real) {
            real = new RealSubject;
        }
        real->Request();
    }
};


int main(int argc, char const *argv[])
{
    Proxy proxy;
    proxy.Request();
    return 0;
}