#include <iostream>

int main()
{
    int target_sum = 1000;

    // Iterate over possible values for a and b
    for (int a = 1; a < target_sum / 2; ++a)
    {
        for (int b = a + 1; b < target_sum / 2; ++b)
        {
            int c = target_sum - a - b; // Calculate c

            if (a * a + b * b == c * c)
            { // Check if it forms a Pythagorean triplet
                long long product = static_cast<long long>(a) * b * c;
                std::cout << "Pythagorean triplet: a = " << a << ", b = " << b << ", c = " << c << std::endl;
                std::cout << "Product of a, b, and c: " << product << std::endl;
                return 0; // We found the solution, no need to continue
            }
        }
    }

    std::cout << "No Pythagorean triplet found for the given sum." << std::endl;
    return 0;
}
