#include<iostream>
using namespace std;

class Cash {
public:
    static double GetTotalPrice(double singlePrice, double total) {
        return singlePrice * total;
    }
};

int main(int argc, char const *argv[])
{
    double price = 0, total = 0;
    cout << "请输入单价: " << endl;
    cin >> price;

    cout << "请输入数量: " << endl;
    cin >> total;

    cout << Cash::GetTotalPrice(price, total);
    return 0;
}
