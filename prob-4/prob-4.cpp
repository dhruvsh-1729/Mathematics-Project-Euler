#include <iostream>
#include <algorithm>
#include <string>

// Function to check if a number is a palindrome
bool isPalindrome(unsigned long long num) {
    std::string str = std::to_string(num);
    std::string reversed_str = str;
    std::reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

// Function to find the largest palindromic number made from the product of two n-digit numbers
unsigned long long largestPalindromeProduct(int digits) {
    unsigned long long max_num = 0;
    unsigned long long min_num = 1;

    // Set min and max numbers for the given number of digits
    for (int i = 1; i < digits; ++i) {
        min_num *= 10;
    }
    max_num = min_num * 10 - 1;

    unsigned long long largest_palindrome = 0;

    // Iterate through all products of two n-digit numbers
    for (unsigned long long i = max_num; i >= min_num; --i) {
        for (unsigned long long j = i; j >= min_num; --j) {
            unsigned long long product = i * j;
            if (product <= largest_palindrome) {
                // If product is less than or equal to the largest palindrome found, break
                break;
            }
            if (isPalindrome(product)) {
                largest_palindrome = product;
            }
        }
    }

    return largest_palindrome;
}

int main() {
    int digits = 3; // Change this for different number of digits
    unsigned long long result = largestPalindromeProduct(digits);
    std::cout << "Largest palindrome made from the product of two " << digits << "-digit numbers is: " << result << std::endl;
    return 0;
}
