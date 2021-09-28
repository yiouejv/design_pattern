#include<iostream>
using namespace std;

class Product {
public:
    virtual void Show() const = 0;
};

class ProductA1 : public Product {
public:
    virtual void Show() const override {
        cout << "ProductA1" << endl;
    }
};

class ProductA2 : public Product {
public:
    virtual void Show() const override {
        cout << "ProductA2" << endl;
    }
};

class ProductB1 : public Product {
public:
    virtual void Show() const override {
        cout << "ProductB1" << endl;
    }
};

class ProductB2 : public Product {
public:
    virtual void Show() const override {
        cout << "ProductB2" << endl;
    }
};

class IFactory {
public:
    virtual Product* CreateProductA() = 0;
    virtual Product* CreateProductB() = 0;
};

class ConcreteFactoryA : public IFactory {
public:
    virtual Product* CreateProductA() override {
        return new ProductA1;
    }
    virtual Product* CreateProductB() override {
        return new ProductB1;
    }
};

class ConcreteFactoryB : public IFactory {
public:
    virtual Product* CreateProductA() override {
        return new ProductA2;
    }
    virtual Product* CreateProductB() override {
        return new ProductB2;
    }
};

int main(int argc, char const *argv[])
{
    ConcreteFactoryA fa;
    Product *a1 = fa.CreateProductA();
    Product *b1 = fa.CreateProductB();
    a1->Show();
    b1->Show();
    delete a1;
    delete b1;

    ConcreteFactoryB fb;
    Product *a2 = fb.CreateProductA();
    Product *b2 = fb.CreateProductB();
    a2->Show();
    b2->Show();
    delete a2;
    delete b2;
    return 0;
}