// Copyright 2022 NNTU-CS
#include "alg.h"

int main() {
    uint64_t value = 29;
    std::cout << checkPrime(value) << std::endl;

    uint64_t n = 10;
    std::cout << nPrime(n) << std::endl;

    std::cout << nextPrime(value) << std::endl;

    uint64_t hbound = 50;
    std::cout << sumPrime(hbound) << std::endl;

    uint64_t lbound = 2;
    std::cout << twinPrimes(lbound, hbound) << std::endl;

    return 0;
}
