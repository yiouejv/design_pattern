#include<iostream>
#include<vector>
using namespace std;

class Recevier {
public:
    void ExecCommandOne() const {
        cout << "command 1" << endl;
    }
    void ExecCommandTwo() const {
        cout << "command 2" << endl;
    }
};

class Command
{
public:
    Recevier recevier;
public:
    Command(const Recevier recevier) : recevier(recevier) {}
    virtual void ExecCommand() = 0;
};

class Command1 : public Command {
public:
    Command1(const Recevier recevier) : Command(recevier) {}
    void ExecCommand() override {
        recevier.ExecCommandOne();
    }
};

class Command2 : public Command {
public:
    Command2(const Recevier recevier) : Command(recevier) {}
    void ExecCommand() override {
        recevier.ExecCommandTwo();
    }
};

class Invoker {
public:
    vector<Command*> vec;
    void AddCommand(Command* comm) {
        vec.push_back(comm);
    }
    void Notify() {
        for (vector<Command*>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
            (*iter)->ExecCommand();
        }
        vec.clear();
    }
};

int main(int argc, const char* argv[])
{
	Recevier recevier;
    Command *pC1 = new Command1(recevier);
    Command *pC2 = new Command2(recevier);

    Invoker invo;
    invo.AddCommand(pC1);
    invo.AddCommand(pC2);
    invo.Notify();
    delete pC1;
    delete pC2;
}
