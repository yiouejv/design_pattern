#include<iostream>
#include<vector>
using namespace std;

class Product {
private:
    vector<string> parts;
public:
    void Add(const string &str) {
        parts.push_back(str);
    }
    void Show() const {
        cout << "Show =============>" << endl;
        for (auto part : parts) {
            cout << part << endl;
        }
    }
};

class Builder {
protected:
    Product product;
public:
    virtual void BuildA() = 0;
    virtual void BuildB() = 0;
    virtual Product GetResult() const = 0;
};

class Director {
public:
    void Build(Builder &build) {
        build.BuildA();
        build.BuildB();
    }
};

class DerivedBuilder1 : public Builder {
public:
    virtual void BuildA() {
        product.Add("DerivedBuilder1 BuildA");
    }
    virtual void BuildB() {
        product.Add("DerivedBuilder1 BuildB");
    }
    virtual Product GetResult() const override {
        return product;
    }
};

class DerivedBuilder2 : public Builder {
public:
    virtual void BuildA() {
        product.Add("DerivedBuilder2 BuildA");
    }
    virtual void BuildB() {
        product.Add("DerivedBuilder2 BuildB");
    }
    virtual Product GetResult() const override {
        return product;
    }
};

int main(int argc, char const *argv[])
{
    DerivedBuilder1 build1;
    DerivedBuilder2 build2;

    Director director;

    director.Build(build1);
    Product p1 = build1.GetResult();
    p1.Show();

    director.Build(build2);
    Product p2 = build2.GetResult();
    p2.Show();
    return 0;
}

