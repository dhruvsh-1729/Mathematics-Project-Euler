#include <bits/stdc++.h>

using namespace std;
#define int unsigned long long
#define SIZE 100000000

// #define SIZE 10

int ans = 0;

vector<bool> prime(SIZE + 10, true);

void sieve(int limit)
{
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= limit; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= limit; j += i)
                prime[j] = false;
        }
    }
}

template <typename T>
void print(vector<T> &v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void sum_limit(int limit)
{
    for (int i = 0; i <= limit; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
            ans += i;
        }
    }

    cout << endl;
}

int32_t main()
{
    sieve(2000000);
    sum_limit(2000000);

    cout << "Final answer is :" << ans << endl;
    return 0;
}