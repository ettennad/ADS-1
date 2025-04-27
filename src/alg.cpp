// Copyright 2022 NNTU-CS
#include <iostream>
#include <cmath>
#include <cstdint>

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    } else if (value == 2) {
        return true;
    } else if (value % 2 == 0) {
        return false;
    }

    uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n < 1) {
        return 0;
    }

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
    uint64_t lastPrime = 0;

    for (uint64_t i = lbound; i < hbound; i++) {
        if (checkPrime(i)) {
            if (lastPrime != 0 && i - lastPrime == 2) {
                count++;
            }
            lastPrime = i;
        }
    }
    return count;
}
