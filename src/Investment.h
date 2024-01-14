#ifdef INVESTMENT_H
#error Already included.
#else
#define INVESTMENT_H

class Investment
{
    public:
        Investment();
        ~Investment();

        void price(fp64 value);
        fp64 price() const;
        fp64 price_total() const;

        void dividend(fp64 value);
        fp64 dividend() const;
        fp64 dividend_total() const;

        void count(size_t value);
        size_t count() const;

        void min_count(size_t value);
        size_t min_count() const;

    private:
        fp64 m_price;
        fp64 m_dividend;
        size_t m_count;
        size_t m_min_count;
};

#endif
