#include <iostream>

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
    unsigned long long result = 1;
    for (int i = 1; i <= 50; ++i) {
        result = lcm(result, i);
    }
    std::cout << "The smallest positive number divisible by all numbers from 1 to 20 is: " << result << std::endl;
    return 0;
}
