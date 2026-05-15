#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <iostream>

class BigInt {
private:
    std::vector<int> digits; // цифры в обратном порядке
public:
    BigInt(long long n = 0);
    void print() const;

    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const; // только для неотрицательных a >= b
    BigInt operator*(int n) const;

    static BigInt powerOfTwo(int n);
};

#endif