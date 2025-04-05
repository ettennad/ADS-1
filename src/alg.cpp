// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

bool checkPrime(uint64_t value) {
    if (value < 2) return false; 
    if (value == 2) return true;
    if (value % 2 == 0) return false;

    for (uint64_t i = 3; i <= sqrt(value); i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n < 1) return 0;

    uint64_t count = 0;
    uint64_t candidate = 2;

    while (count < n) {
        if (checkPrime(candidate)) {
            count++;
        }
        candidate++;
    }
    return candidate - 1;
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (!checkPrime(value)) {
        value++;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    bool prevPrime = checkPrime(lbound);

    for (uint64_t i = lbound + 1; i < hbound; i++) {
        if (checkPrime(i)) {
            if (prevPrime && (i - (i - 1) == 2)) {
                count++;
            }
            prevPrime = true;
        } else {
            prevPrime = false;
        }
    }
    return count;
}
