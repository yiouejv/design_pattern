#include<iostream>
#include<vector>
using namespace std;

class Handler {
public:
    Handler *nextHandler;
public:
    Handler() {}
    virtual ~Handler() {
        if (nextHandler) {
            delete nextHandler;
        }
    }
    void SetNextHandler(Handler* handler) {
        nextHandler = handler;
    }
    virtual void HandleRequest(int request) = 0;
};

class Handler1 : public Handler {
public:
    void HandleRequest(int request) override {
        if (request >= 0 && request <= 10) {
            cout << "handler1 handle request " << request << endl;
        } else if (nextHandler) {
            nextHandler->HandleRequest(request);
        }
    }
};

class Handler2 : public Handler {
public:
    void HandleRequest(int request) override {
        if (request > 10 && request <= 20) {
            cout << "handler2 handle request " << request << endl;
        } else if (nextHandler) {
            nextHandler->HandleRequest(request);
        }
    }
};

class Handler3 : public Handler {
public:
    void HandleRequest(int request) override {
        if (request > 20 && request <= 30) {
            cout << "handler3 handle request " << request << endl;
        } else if (nextHandler) {
            nextHandler->HandleRequest(request);
        }
    }
};


int main(int argc, const char* argv[])
{
    Handler *h1 = new Handler1;
    Handler *h2 = new Handler2;
    Handler *h3 = new Handler3;

    h1->SetNextHandler(h2);
    h2->SetNextHandler(h3);

    vector<int> vec{ 1, 2, 3, 4, 30, 29, 18, 15, 20, 22};
    for (int n : vec) {
        h1->HandleRequest(n);
    }
    return 0;
}
