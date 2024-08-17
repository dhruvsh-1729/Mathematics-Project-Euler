#include <iostream>
#include <cmath>

// Function to find the largest prime factor
unsigned long long largestPrimeFactor(unsigned long long n) {
    if (n < 2) return 0;

    // Variable to store the largest prime factor
    unsigned long long largest = 0;

    // Remove factors of 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Remove factors of 3
    while (n % 3 == 0) {
        largest = 3;
        n /= 3;
    }

    // Remove factors of 6k ± 1, starting with 5
    for (unsigned long long i = 5; i <= std::sqrt(n); i += 6) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
        while (n % (i + 2) == 0) {
            largest = i + 2;
            n /= (i + 2);
        }
    }

    // If n is still greater than 2, it is a prime number
    if (n > 2) {
        largest = n;
    }

    return largest;
}

int main() {
    unsigned long long number = 600851475143; // Example number
    std::cout << "Largest prime factor: " << largestPrimeFactor(number) << std::endl;
    return 0;
}
