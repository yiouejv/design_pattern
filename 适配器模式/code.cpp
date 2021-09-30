#include<iostream>
using namespace std;


class Target {
public:
    virtual ~Target() {}
    virtual void Request() = 0;
};

class Adaptee {
public:
    void SpecificRequest() const {
        cout << "Adaptee SpecificRequest" << endl;
    }
};

class Adapter : public Target {
private:
    Adaptee *ade = nullptr;
public:
    Adapter() {
        ade = new Adaptee;
    }
    ~Adapter() {
        if (ade) {
            delete ade;
        }
    }
    virtual void Request() override {
        ade->SpecificRequest();
    }
};

int main(int argc, char const* argv[])
{
    Target* tar = new Adapter();
    tar->Request();
    delete tar;
    return 0;
}



