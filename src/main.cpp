#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <list>

#include "Types.h"
#include "Investment.h"

namespace
{
    template <class T> std::string invest_str(T const &investments)
    {
        std::string result { };

        for (auto &invest: investments)
        {
            std::string const str = std::to_string(invest->count());

            if (result.empty())
            {
                result.append(str);
            }
            else
            {
                result.append("\t");
                result.append(str);
            }
        }

        return result;
    }

    template <class T> fp64 invest_total(T const &investments)
    {
        fp64 result = 0.0;

        for (auto &invest: investments)
        {
            result += invest->price_total();
        }

        return result;
    }

    template <class T> fp64 dividend_total(T const &investments)
    {
        fp64 result = 0.0;

        for (auto &invest: investments)
        {
            result += invest->dividend_total();
        }

        return result;
    }
}

int main(int, char *[])
{
    fp64 const I_max = 20.0E3;
    fp64 const I_min = (I_max - 500.0);

    Investment A { };
    A.price(6.85);
    A.dividend(0.47);
    A.min_count(100U);
    A.count(A.min_count());

    Investment B { };
    B.price(62.50);
    B.dividend(5.20);
    B.min_count(20U);
    B.count(B.min_count());

    Investment C { };
    C.price(48.50);
    C.dividend(3.40);
    C.min_count(20U);
    C.count(C.min_count());

    Investment D { };
    D.price(18.0);
    D.dividend(1.15);
    D.min_count(50U);
    D.count(D.min_count());

    std::list<Investment *> Investments
    {
        &A, &B, &C, &D
    };

    std::cout << std::setprecision(10) << "Investment (max): " << I_max << std::endl;

    fp64 max_dividends = 0.0;

    bool finished = false;
    size_t loop_count = 0U;

    while (not finished)
    {
        ++loop_count;

        {
            auto const invest_total = ::invest_total(Investments);

            if (invest_total > I_min)
            {
                auto const divid_total = ::dividend_total(Investments);

                if (divid_total >= max_dividends)
                {
                    auto const invest_str = ::invest_str(Investments);

                    std::cout << invest_str << "\t" << invest_total << "\t" << divid_total << std::endl;

                    max_dividends = divid_total;
                }
            }
        }

        size_t miss_count = 0U;

        for (auto &invest: Investments)
        {
            auto const count = invest->count();
            invest->count(count + 1U);

            auto const invest_total = ::invest_total(Investments);

            if (invest_total < I_max)
            {
                break;
            }

            invest->count(invest->min_count());
            ++miss_count;
        }

        finished = (miss_count >= Investments.size());
    }

    std::cout << "Loop counter: " << loop_count << std::endl;

    return EXIT_SUCCESS;
}
