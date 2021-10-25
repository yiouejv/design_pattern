#include<iostream>
#include<vector>
using namespace std;

class Iterator {
public:
    virtual int First() const = 0;
    virtual int End() const = 0;
    virtual bool IsDone() const = 0;
    virtual bool Next() = 0;
    virtual int CurrentItem() const = 0;
};

class Aggregate {
public:
    virtual Iterator* CreateIterator() const = 0;
    virtual int Count() const = 0;
    virtual void Push(int value) = 0;
    virtual int Pop(int index) const = 0;
};

class ConcreteIterator : public Iterator {
private:
    const Aggregate* aggregate;
    int count;
    int currentIndex;
public:
    explicit ConcreteIterator(const Aggregate* aggregate) : aggregate(aggregate) {
        count = aggregate->Count();
        currentIndex = 0;
    }

    ~ConcreteIterator() {
        if (aggregate) {
            delete aggregate;
        }
    }

    int First() const override {
        return aggregate->Pop(0);
    }
    int End() const override {
        return aggregate->Pop(count - 1);
    }
    bool IsDone() const override {
        return currentIndex == count ? true : false;
    }
    bool Next() override {
        if (!IsDone()) {
            ++currentIndex;
            return true;
        }
        return false;
    }
    int CurrentItem() const override {
        int p;
        if (!IsDone()) {
            p = aggregate->Pop(currentIndex);
        }
        return p;
    }
};

class ConcreteAggregate : public Aggregate {
private:
    vector<int> vec;
public:
    Iterator* CreateIterator() const override {
        return new ConcreteIterator(this);
    }
    int Count() const override {
        return vec.size();
    }
    void Push(int value) override {
        vec.push_back(value);
    }

    int Pop(int index) const override {
        return vec[index];
    }
};


int main(int argc, char const* argv[])
{
    ConcreteAggregate aggregate;
    aggregate.Push(1);
    aggregate.Push(2);
    aggregate.Push(3);

    Iterator *iter = aggregate.CreateIterator();
    while (!iter->IsDone())
    {
        cout << iter->CurrentItem() << endl;
        iter->Next();
    }

    cout << "first: " << iter->First() << endl;
    cout << "end: " << iter->End() << endl;
    delete iter;
    return 0;
}