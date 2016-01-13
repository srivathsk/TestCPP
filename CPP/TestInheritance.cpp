#include <iostream>
using namespace std;

class company {
    public:
        company(double price, double revenue)
            : m_price(price),
              m_revenue(revenue)
        {}

        double getPrice()
        { return m_price; }

        double getRevenue()
        {
            return m_revenue; }

   private:
        double m_price;
        double m_revenue;
};

class KT : public company {
    public: 
        KT(double price, double revenue)
            : company(price, revenue)
        { }
};

int main() {
    KT* KT1 = new KT(100.0, 100000000);
    KT* KT2 = new KT(60.0, 1232323232);

    cout << "Price of KT1 " << KT1->getPrice() << endl;
    cout << "Revenue of KT1 " << KT1->getRevenue() << endl;
    cout << "Price of KT2 " << KT2->getPrice() << endl;
    cout << "Revenue of KT2 " << KT2->getRevenue() << endl;
}



