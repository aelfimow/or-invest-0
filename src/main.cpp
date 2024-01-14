#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

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

        void dividend(fp64 value)
        {
            m_dividend = value;
        }

        fp64 dividend() const
        {
            return m_dividend;
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

int main(int, char *[])
{
    fp64 const I_max = 10.0E3;

    std::cout << std::setprecision(10) << "Investment (max): " << I_max << std::endl;

    return EXIT_SUCCESS;
}
