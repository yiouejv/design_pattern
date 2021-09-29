#include<iostream>
using namespace std;

class Context;

class State {
public:
    virtual void Handle(Context* ctx) = 0;
    virtual ~State() {}
};

class ConcreteStateA : public State {
public:
    virtual void Handle(Context* ctx) override;
};

class ConcreteStateB : public State {
public:
    virtual void Handle(Context* ctx) override;
};

class ConcreteStateC : public State {
public:
    virtual void Handle(Context* ctx) override;
};

class ConcreteStateD : public State {
public:
    virtual void Handle(Context* ctx) override;
};

class Context {
public:
    State* state;
    Context(State *s) {
        state = s;
    }
    ~Context() {
        if (state) {
            delete state;
        }
    }
    void Request();
};

void Context::Request() {
    state->Handle(this);
}

void ConcreteStateA::Handle(Context *ctx) {
    cout << "state A handle" << endl;
    ctx->state = new ConcreteStateB;
}

void ConcreteStateB::Handle(Context *ctx) {
    cout << "state B handle" << endl;
    ctx->state = new ConcreteStateC;
}

void ConcreteStateC::Handle(Context *ctx) {
    cout << "state C handle" << endl;
    ctx->state = new ConcreteStateD;    
}

void ConcreteStateD::Handle(Context *ctx) {
    cout << "state D handle" << endl;
}


int main(int argc, char const* argv[])
{
	ConcreteStateA s;
    Context ctx(&s);
    ctx.Request();
    ctx.Request();
    ctx.Request();
    ctx.Request();
    return 0;
}