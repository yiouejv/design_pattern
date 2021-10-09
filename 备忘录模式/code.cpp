#include<iostream>
#include<string>
using namespace std;

class Memento {
public:
    string state;  // 需要保存的数据，可以是多个
    Memento(const string &s) : state(s) {}
};

class Originator {
private:
    string state;
public:
    Originator(const string &s) : state(s) { }

    // 创建备忘录，将需要保存的信息传入，创建一个 Memento 对象
    Memento CreateMemento() {
        return Memento(state);
    }

    // 恢复备忘录，将 Memento 导入并将相关数据恢复
    void SetMemento(const Memento &m) {
        state = m.state;
    }

    void SetState(const string &s) {
        state = s;
    }

    void Display() const {
        cout << "originator state: " << state << endl;
    }
};

class Caretaker {
public:
    Memento memnto;
    Caretaker(const Memento &m) : memnto(m) {}
};


int main(int argc, char const *argv[])
{
    Originator o("状态1");
    o.Display();

    // 备份
    Memento m = o.CreateMemento();
    Caretaker c(m);

    o.SetState("状态2");
    o.Display();

    o.SetMemento(c.memnto);
    o.Display();
    return 0;
}