#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

int collatz_steps(int n)
{
    int steps = 0;
    while (n > 1)
    {
        if (n & 1)
        {
            n = (3 * n + 1) / 2;
            steps += 2;
        }
        else
        {
            n /= 2;
            steps += 1;
        }
    }

    return steps;
}

int32_t main()
{

    int ans = 0, maxi = 0;

    for (int i = 1; i < 1000000; i++)
    {
        int steps = collatz_steps(i);
        if (steps > maxi)
        {
            maxi = steps;
            ans = i;

            cout << ans << " " << steps << endl;
        }
    }

    cout << ans << endl;

    return 0;
}