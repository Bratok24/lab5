#include <iostream>
#include "BigInt.h"

BigInt factorial(int n) {
    BigInt res(1);
    for (int i = 2; i <= n; ++i)
        res = res * i;
    return res;
}

BigInt fibonacci(int n) {
    if (n == 0) return BigInt(0);
    BigInt a(0), b(1);
    for (int i = 2; i <= n; ++i) {
        BigInt next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int input_1, input_2;

    std::cout << "1. Factorial (n > 100): ";
    std::cin >> input_1;
    factorial(input_1).print();

    std::cout << "2. 2^n - 1 (n > 64): ";
    std::cin >> input_1;
    (BigInt::powerOfTwo(input_1) - BigInt(1)).print();

    std::cout << "3. (2^a - 1) + (2^b - 1) (a,b > 64): ";
    std::cin >> input_1 >> input_2;
    BigInt val1 = BigInt::powerOfTwo(input_1) - BigInt(1);
    BigInt val2 = BigInt::powerOfTwo(input_2) - BigInt(1);
    (val1 + val2).print();

    std::cout << "4. 2^a - 2^b (a > b, > 64): ";
    std::cin >> input_1 >> input_2;
    (BigInt::powerOfTwo(input_1) - BigInt::powerOfTwo(input_2)).print();

    std::cout << "5. Fibonacci (n > 100): ";
    std::cin >> input_1;
    fibonacci(input_1).print();

    return 0;
}