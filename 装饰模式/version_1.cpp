#include<iostream>
#include<string>
using namespace std;

class Person {
private:
    string m_name;
public:
    Person() = delete;
    Person(const string& name) : m_name(name) { }

    virtual void Show() {
        cout << "我的名字是: " << m_name << endl;
    }
};

class Decorate : public Person {
protected:
    Person* m_person;
public:
    Decorate(const string& name) : Person(name) {}
    ~Decorate() {
        if (m_person != nullptr) {
            delete m_person;
        }
    }
    void DecorateTarget(Person* person) {
        this->m_person = person;
    }
    virtual void Show() = 0;
};


class TShirt : public Decorate {
public:
    TShirt(const string& name = "T恤") : Decorate(name) { }
    void Show() override {
        if (m_person) {
            m_person->Show();
        }
        cout << "穿着T恤衫" << endl;
    }
};

class Hat : public Decorate {
public:
    Hat(const string& name = "帽子") : Decorate(name) { }
    void Show() override {
        if (m_person) {
            m_person->Show();
        }
        cout << "带着帽子" << endl;
    }
};


int main(int argc, char const* argv[])
{
    Person *person = new Person("杨小哥");
    //person->Show();

    TShirt *ts = new TShirt;
    ts->DecorateTarget(person);
    //ts->Show();

    Hat *hat = new Hat;
    hat->DecorateTarget(ts);
    hat->Show();
    return 0;
}