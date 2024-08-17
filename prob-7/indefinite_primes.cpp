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

// Function to find new primes indefinitely
void findPrimesIndefinitely() {
    unsigned long long limit = 100; // Starting limit
    std::vector<unsigned long long> primes = sieve(limit);
    unsigned long long last_prime = primes.back();
    int prime_count = primes.size();

    while (true) {
        limit *= 2; // Double the limit to find more primes
        std::vector<unsigned long long> new_primes = sieve(limit);
        
        // Find new primes that are beyond the last known prime
        for (size_t i = prime_count; i < new_primes.size(); ++i) {
            std::cout << "New prime: " << new_primes[i] << std::endl;
        }
        
        // Update the last prime and count
        last_prime = new_primes.back();
        prime_count = new_primes.size();

        // Sleep to reduce CPU usage (optional)
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    findPrimesIndefinitely();
    return 0;
}
