#include "BigInt.h"
#include <algorithm>

BigInt::BigInt(long long n) {
    if (n == 0) digits.push_back(0);
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
}

void BigInt::print() const {
    for (int i = (int)digits.size() - 1; i >= 0; --i)
        std::cout << digits[i];
    std::cout << std::endl;
}

BigInt BigInt::operator+(const BigInt& other) const {
    BigInt res;
    int carry = 0;
    size_t n = std::max(digits.size(), other.digits.size());
    for (size_t i = 0; i < n || carry; ++i) {
        int d1 = i < digits.size() ? digits[i] : 0;
        int d2 = i < other.digits.size() ? other.digits[i] : 0;
        int sum = d1 + d2 + carry;
        res.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    return res;
}

BigInt BigInt::operator-(const BigInt& other) const {
    BigInt res = *this;
    while (res.digits.size() < other.digits.size())
        res.digits.push_back(0);
    int borrow = 0;
    for (size_t i = 0; i < res.digits.size(); ++i) {
        int sub = (i < other.digits.size() ? other.digits[i] : 0) + borrow;
        if (res.digits[i] < sub) {
            res.digits[i] = res.digits[i] + 10 - sub;
            borrow = 1;
        } else {
            res.digits[i] -= sub;
            borrow = 0;
        }
    }
    while (res.digits.size() > 1 && res.digits.back() == 0)
        res.digits.pop_back();
    return res;
}

BigInt BigInt::operator*(int n) const {
    if (n == 0) return BigInt(0);
    BigInt res;
    long long carry = 0;
    for (size_t i = 0; i < digits.size() || carry; ++i) {
        long long cur = carry;
        if (i < digits.size())
            cur += static_cast<long long>(digits[i]) * n;
        res.digits.push_back(static_cast<int>(cur % 10));
        carry = cur / 10;
    }
    return res;
}

BigInt BigInt::powerOfTwo(int n) {
    BigInt res(1);
    for (int i = 0; i < n; ++i)
        res = res * 2;
    return res;
}