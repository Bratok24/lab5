#include "logic.h"
#include <limits>
#include <cstdint>

int custom_divide(int dividend, int divisor) {
    if (divisor == 0) return std::numeric_limits<int>::max();
    if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
        return std::numeric_limits<int>::max();
    }

    uint32_t dvd = dividend < 0 ? (~dividend + 1) : dividend;
    uint32_t dvs = divisor < 0 ? (~divisor + 1) : divisor;

    uint32_t quotient = 0;

    for (int i = 31; i >= 0; i--) {
        if ((dvd >> i) >= dvs) {
            uint32_t shifted_dvs = (dvs << i);
            dvd += (~shifted_dvs + 1);
            quotient |= (1U << i);
        }
    }

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    return sign == -1 ? (~quotient + 1) : quotient;
}