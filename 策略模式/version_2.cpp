#include<iostream>
using namespace std;

class CashSuper {
public:
    virtual double GetTotalPrice(double singlePrice, double total) {
        return singlePrice * total;
    }
};

class CashNormal : public CashSuper {
public:
    double GetTotalPrice(double singlePrice, double total) override {
        return singlePrice * total;
    }
};

class CashDiscount : public CashSuper {
private:
    double discount = 1;
public:
    CashDiscount(double disc) : discount(disc) {};
    double GetTotalPrice(double singlePrice, double total) override {
        return singlePrice * total * discount;
    }
};

class CashReturn : public CashSuper {
private:
    double moneyCondition = 0;
    double moneyReturn = 0;
public:
    CashReturn() = delete;
    CashReturn(double condition, double ret) : moneyCondition(condition), moneyReturn(ret) {};

    double GetTotalPrice(double singlePrice, double total) override {
        double totalPrice = singlePrice * total;
        if (totalPrice > moneyCondition) {
            totalPrice = totalPrice - floor(totalPrice / moneyCondition) * moneyReturn;
        }
        return totalPrice;
    }
};

class CashFactory {
public:
    static CashSuper* CreateCash(string& discountStr) {
        if (discountStr == "正常收费") {
            return new CashNormal;

        }
        else if (discountStr == "打八折") {
            return new CashDiscount(0.8);

        }
        else if (discountStr == "满200减100") {
            return new CashReturn(200, 100);
        }
        else {
            throw;
        }
    }
};

int main(int argc, char const* argv[])
{
    double price = 0, total = 0;
    int type;
    cout << "请输入单价: " << endl;
    cin >> price;

    cout << "请输入数量: " << endl;
    cin >> total;

    cout << "请输入收费类型: " << endl
        << "1 正常收费, " << endl
        << "2 打八折, " << endl
        << "3 满200减100." << endl;
    cin >> type;

    string str;
    if (type == 1) {
        str.assign("正常收费");

    }
    else if (type == 2) {
        str.assign("打八折");

    }
    else if (type == 3) {
        str.assign("满200减100");

    }
    else {
        cout << "收费类型不对" << endl;
    }

    CashSuper* cash = CashFactory::CreateCash(str);
    cout << cash->GetTotalPrice(price, total);
    return 0;
}
