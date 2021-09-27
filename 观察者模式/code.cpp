#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BaseObserver {
public:
    string state;
    string m_name;
    virtual void Update(const string& n, const string& st) = 0;
};

class BaseSubject {
public:
    vector<BaseObserver*> observers;
    string subState;
    string m_name;
    virtual void Add(BaseObserver*) = 0;
    virtual void Delete(BaseObserver*) = 0;
    virtual void Notify() = 0;
};

class SubjectA : public BaseSubject {
public:
    SubjectA(const string& name) {
        m_name = name;
    };

    virtual void Add(BaseObserver* ob) override {
        observers.push_back(ob);
    }

    virtual void Delete(BaseObserver* ob) override {
        for (auto iter = observers.begin(); iter != observers.end();) {
            if (*iter == ob) {
                observers.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

    virtual void Notify() override {
        for (auto p : observers) {
            p->Update(m_name, subState);
        }
    }
};

class Observer : public BaseObserver {
public:
    Observer(const string& name) {
        m_name = name;
    };
    virtual void Update(const string& n, const string& st) override {
        state = st;
        cout << "selfNmae: " << m_name
            << " state: " << state
            << " event name: " << n
            << endl;
    }
};

int main(int argc, char const* argv[])
{
    Observer ob1("ob1");
    Observer ob2("ob2");
    SubjectA sub("subjectA");

    sub.Add(&ob1);
    sub.Add(&ob2);
    sub.Delete(&ob1);
    sub.subState = "状态改变了";
    sub.Notify();
    return 0;
}