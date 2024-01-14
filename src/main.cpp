#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <list>

using fp64 = double;
static_assert(sizeof(fp64) == 8U);

class Investment
{
    public:
        Investment() :
            m_price { 0.0 },
            m_dividend { 0.0 },
            m_count { 0 }
        {
        }

        ~Investment()
        {
        }

        void price(fp64 value)
        {
            m_price = value;
        }

        fp64 price() const
        {
            return m_price;
        }

        fp64 price_total() const
        {
            fp64 const count = static_cast<fp64>(m_count);
            fp64 const result = (m_price * count);
            return result;
        }

        void dividend(fp64 value)
        {
            m_dividend = value;
        }

        fp64 dividend() const
        {
            return m_dividend;
        }

        fp64 dividend_total() const
        {
            fp64 const count = static_cast<fp64>(m_count);
            fp64 const result = (m_dividend * count);
            return result;
        }

        void count(size_t value)
        {
            m_count = value;
        }

        size_t count() const
        {
            return m_count;
        }

    private:
        fp64 m_price;
        fp64 m_dividend;
        size_t m_count;
};

namespace
{
    template <class T> fp64 invest_total(T const &investments)
    {
        fp64 result = 0.0;

        for (auto &invest: investments)
        {
            result += invest->price_total();
        }

        return result;
    }
}

int main(int, char *[])
{
    fp64 const I_max = 10.0E3;

    Investment A { };
    Investment B { };
    Investment C { };

    A.price(45.0);
    A.dividend(3.40);
    A.count(1U);

    B.price(99.0);
    B.dividend(5.96);
    B.count(1U);

    C.price(12.6);
    C.dividend(0.51);
    C.count(1U);

    std::list<Investment *> Investments
    {
        &A, &B, &C
    };

    std::cout << std::setprecision(10) << "Investment (max): " << I_max << std::endl;

    fp64 const invest_total = ::invest_total(Investments);
    std::cout << "Investment total: " << invest_total << std::endl;

    return EXIT_SUCCESS;
}
