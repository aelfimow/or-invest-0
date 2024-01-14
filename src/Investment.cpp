#include <cstddef>

#include "Types.h"
#include "Investment.h"

Investment::Investment() :
    m_price { 0.0 },
    m_dividend { 0.0 },
    m_count { 0 },
    m_min_count { 0 }
{
}

Investment::~Investment()
{
}

void Investment::price(fp64 value)
{
    m_price = value;
}

fp64 Investment::price() const
{
    return m_price;
}

fp64 Investment::price_total() const
{
    fp64 const count = static_cast<fp64>(m_count);
    fp64 const result = (m_price * count);
    return result;
}

void Investment::dividend(fp64 value)
{
    m_dividend = value;
}

fp64 Investment::dividend() const
{
    return m_dividend;
}

fp64 Investment::dividend_total() const
{
    fp64 const count = static_cast<fp64>(m_count);
    fp64 const result = (m_dividend * count);
    return result;
}

void Investment::count(size_t value)
{
    m_count = value;
}

size_t Investment::count() const
{
    return m_count;
}

void Investment::min_count(size_t value)
{
    m_min_count = value;
}

size_t Investment::min_count() const
{
    return m_min_count;
}
