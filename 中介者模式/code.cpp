#include<iostream>
#include<string>
using namespace std;

class Colleague;
class Mediator {
public:
    Colleague *gue1;
    Colleague *gue2;

    virtual void Send(const string &msg, Colleague * const gue) = 0;
};

class Colleague {
private:
    Mediator *mediator;

public:
    Colleague(Mediator *media) : mediator(media) {}
    virtual void Notify(const string &msg) = 0;
    void Send(const string &msg) {
        mediator->Send(msg, this);
    }
};

class ConcreteColleague1 : public Colleague {
public:
    ConcreteColleague1(Mediator *mediator) : Colleague(mediator) {}
    void Notify(const string &msg) override {
        cout << "to Colleague1: " << msg << endl;
    }
};

class ConcreteColleague2 : public Colleague {
public:
    ConcreteColleague2(Mediator *mediator) : Colleague(mediator) {}
    void Notify(const string &msg) override {
        cout << "to Colleague2: " << msg << endl;
    }
};

class ConcreteMediator : public Mediator {
public:
    void Send(const string &msg, Colleague *gue) override {
        if (gue == gue1) {
            gue2->Notify(msg);
        } else if ( gue == gue2 ) {
            gue1->Notify(msg);
        } else;
    }
};

int main(int argc, const char* argv[])
{
    ConcreteMediator *mediator = new ConcreteMediator;
    ConcreteColleague1 *gue1 = new ConcreteColleague1(mediator);
    ConcreteColleague2 *gue2 = new ConcreteColleague2(mediator);

    mediator->gue1 = gue1;
    mediator->gue2 = gue2;

    gue1->Send("你吃了吗？");
    gue2->Send("我吃了");
    delete mediator;
    delete gue1;
    delete gue2;
    return 0;
}
