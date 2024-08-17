#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

int32_t main()
{
    const int limit = 4000000; // Upper limit for Fibonacci numbers
    int a = 1, b = 2;          // Starting values of Fibonacci sequence
    int sum = 0;               // To store the sum of even-valued terms

    // Iterate until we exceed the limit
    while (b <= limit)
    {
        // If the current term is even, add it to the sum
        if (b % 2 == 0)
        {
            sum += b;
        }

        // Move to the next term in the sequence
        int next = a + b; // Compute the next Fibonacci number
        a = b;            // Update 'a' to the previous term
        b = next;         // Update 'b' to the new term
    }

    // Output the result
    std::cout << "Sum of even-valued terms: " << sum << std::endl;

    return 0;
}
