#include<iostream>
#include<string>
using namespace std;
        
class ProtoType {};

class cloneable : public ProtoType {
    virtual ProtoType* clone() = 0;
};

class Resume : public cloneable {
private:
    string m_name;
    int m_age;
public:
    void SetInfo(const string &name, int age) {
        m_name = name;
        m_age = age;
    }
    void display() {
        cout << "名字是: " << m_name << endl
             << "年龄是: " << m_age << endl;
    }
    virtual Resume* clone() override {
        return new Resume(*this);
    }
};

int main(int argc, char const *argv[])
{
    Resume resume;
    resume.SetInfo("杨小哥", 18);
    resume.display();

    Resume *resume2 = resume.clone();
    resume2->SetInfo("杨小哥", 20);
    resume2->display();
    return 0;
}