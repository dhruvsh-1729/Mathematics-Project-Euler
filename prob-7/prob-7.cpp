#include <iostream>
#include <vector>
#include <cmath>

// Function to estimate the upper limit for the nth prime
unsigned long long estimateUpperLimit(int n) {
    if (n < 6) return 15; // Handle small cases
    return static_cast<unsigned long long>(n * (std::log(n) + std::log(std::log(n))));
}

// Function to generate primes using the Sieve of Eratosthenes
std::vector<unsigned long long> sieve(unsigned long long limit) {
    std::vector<bool> is_prime(limit + 1, true);
    std::vector<unsigned long long> primes;
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes

    for (unsigned long long p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (unsigned long long multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    for (unsigned long long p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

// Function to find the nth prime number
unsigned long long findNthPrime(int n) {
    unsigned long long upper_limit = estimateUpperLimit(n);
    std::vector<unsigned long long> primes = sieve(upper_limit);

    if (n <= primes.size()) {
        return primes[n - 1];
    } else {
        throw std::runtime_error("The estimated upper limit was too low.");
    }
}

int main() {
    int n = 10001;

    try {
        unsigned long long nth_prime = findNthPrime(n);
        std::cout << "The " << n << "th prime number is: " << nth_prime << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
