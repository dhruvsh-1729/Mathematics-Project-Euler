#include <iostream>
#include <limits>

// Function to calculate the greatest common divisor (GCD)
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM)
unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    const unsigned long long MAX_LIMIT = std::numeric_limits<unsigned long long>::max();
    unsigned long long result = 1;
    int number = 1;

    while (true) {
        try {
            // Calculate LCM with the next number
            unsigned long long next_result = lcm(result, number + 1);
            if (next_result < result || next_result > MAX_LIMIT) {
                // If the result exceeds the limit or overflows, break
                break;
            }
            result = next_result;
            ++number;
        } catch (...) {
            // Catch any overflow exception (if supported)
            break;
        }
    }

    std::cout << "The largest number for which LCM can be computed accurately is: " << number << std::endl;
    std::cout << "The LCM for numbers from 1 to " << number << " is: " << result << std::endl;
    
    return 0;
}
