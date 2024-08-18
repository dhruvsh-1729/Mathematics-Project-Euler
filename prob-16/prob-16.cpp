#include <iostream>
#include <string>
#include <cmath>

int main() {
    // Calculate 2^1000
    unsigned long long result[302] = {0};  // 302 is enough to hold the digits of 2^1000
    result[0] = 1;
    int digits = 1;
    
    for (int i = 0; i < 1000; ++i) {
        unsigned long long carry = 0;
        for (int j = 0; j < digits; ++j) {
            unsigned long long temp = result[j] * 2 + carry;
            result[j] = temp % 10;
            carry = temp / 10;
        }
        while (carry > 0) {
            result[digits] = carry % 10;
            carry /= 10;
            ++digits;
        }
    }

    // Sum the digits
    int sum = 0;
    for (int i = 0; i < digits; ++i) {
        sum += result[i];
    }

    std::cout << "The sum of the digits of 2^1000 is: " << sum << std::endl;

    return 0;
}
