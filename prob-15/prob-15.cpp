#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

int count_paths(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return dp[0][0] = 1;
    if (m == 0)
        return dp[m][n] = count_paths(m, n - 1, dp);
    if (n == 0)
        return dp[m][n] = count_paths(m - 1, n, dp);
    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = count_paths(m - 1, n, dp) + count_paths(m, n - 1, dp);
}

int32_t main()
{
    vector<vector<int>> dp(21, vector<int>(21, -1)); // Use 21x21 to represent paths between 20x20 grid points
    cout << count_paths(20, 20, dp) << endl;
}
