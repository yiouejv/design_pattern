#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Component {
private:
    string name;
    vector<Component*> vec;
public:
    Component(const string &name) : name(name) {}
    ~Component() {
        for (Component *p : vec) {
            if (p) {
                delete p;
            }
        }
    }
    virtual void Add(Component *c) {
        vec.push_back(c);
    }
    virtual void Remove(Component *c) {
        for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
            if (*iter == c) {
                vec.erase(iter);
            }
        }
    }
    void Display(int depth) const {
        cout << string(depth, '-') << name << endl;
        for (Component *c : vec) {
            c->Display(depth + 2);
        }
    }
    virtual void Work() const {
        cout << name << " work!" << endl;
        for (Component *c : vec) {
            c->Work();
        }
    }
};

class Composite : public Component {
public:
    Composite(const string& name) : Component(name) {}
    ~Composite() {}
};

class Leaf : public Component {
public:
    Leaf(const string& name) : Component(name) {}
    ~Leaf() {}
    void Add(Component *c) override {
        cout << "Leaf cannot Add!" << endl;
    }
    void Remove(Component *c) override {
        cout << "Leaf cannot Remove!" << endl;
    }
};


int main(int argc, char const *argv[])
{
    Composite root("root");
    Composite compX("composite x");
    Composite compY("composite y");
    root.Add(&compX);
    root.Add(&compY);

    Composite compXX("composite xx");
    Composite compXY("composite xy");
    compX.Add(&compXX);
    compX.Add(&compXY);

    Composite compYX("composite yx");
    Composite compYY("composite yy");
    compY.Add(&compYX);
    compY.Add(&compYY);

    root.Display(1);
    root.Work();
    return 0;
}