#include<iostream>
#include<string>
using namespace std;

class Resume {
private:
    string m_name;
    int m_age;
public:
    Resume() { }
    Resume(const Resume& resume) {
        m_name = resume.m_name;
        m_age = resume.m_age;
    }

    void SetInfo(const string& name, int age) {
        m_name = name;
        m_age = age;
    }

    void display() const {
        cout << "名字是: " << m_name << endl
             << "年龄是: " << m_age << endl;
    }
};

int main(int argc, char const *argv[])
{
    Resume resume;
    resume.SetInfo("杨小哥", 18);
    resume.display();

    Resume resume2 = resume;
    resume2.display();

    Resume *p = &resume;
    Resume resume3 = *p;
    resume3.display();
    return 0;
}