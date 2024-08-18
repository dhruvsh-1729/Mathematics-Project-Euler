#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> generatePrimes(int limit)
{
    std::vector<bool> isPrime(limit + 1, true);
    std::vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= limit; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}

int countDivisorsUsingPrimes(int n, const std::vector<int> &primes)
{
    int divisors = 1;
    int remaining = n;

    for (int prime : primes)
    {
        if (prime * prime > n)
            break;

        int exponent = 0;
        while (remaining % prime == 0)
        {
            remaining /= prime;
            exponent++;
        }

        divisors *= (exponent + 1);
        if (remaining == 1)
            break;
    }

    if (remaining > 1)
    {
        divisors *= 2;
    }

    return divisors;
}

int findTriangleNumberWithDivisors(int divisorLimit)
{
    int triangleNumber = 0;
    int index = 1;

    std::vector<int> primes = generatePrimes(100000);

    while (true)
    {
        triangleNumber += index;
        index++;

        int divisors = countDivisorsUsingPrimes(triangleNumber, primes);
        std::cout << index << " " << divisors << std::endl;
        if (divisors > divisorLimit)
        {
            return triangleNumber;
        }
    }
}

int main()
{
    int divisorLimit = 1000;
    int result = findTriangleNumberWithDivisors(divisorLimit);

    std::cout << "The first triangle number with over " << divisorLimit << " divisors is: " << result << std::endl;

    return 0;
}
