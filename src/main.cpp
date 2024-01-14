#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using fp64 = double;
static_assert(sizeof(fp64) == 8U);

int main(int, char *[])
{
    fp64 const I_max = 10.0E3;

    std::cout << std::setprecision(10) << "Investment (max): " << I_max << std::endl;

    return EXIT_SUCCESS;
}
