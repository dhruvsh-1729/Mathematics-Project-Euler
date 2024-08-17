#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int number = 1000;                                                         // The upper limit for numbers to consider
int ans = 0;                                                                              // Variable to store the result
vector<int> nums = {3, 5 }; // List of numbers to consider

//Largest number for which this gives an answer : 1000000000000000000

void print(const vector<int> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute the LCM of two numbers
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

// Function to find the LCM of an array of numbers
int findLCM(const vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
        result = lcm(result, nums[i]);
    }
    return result;
}

// Function to compute the sum of multiples of LCM
void add_sum(const vector<int> &curr_comb, int sign)
{
    int lcm_val = findLCM(curr_comb);
    if (lcm_val == 0)
        return; // Avoid division by zero

    // Calculate the number of terms below 'number'
    int number_of_terms = (number - 1) / lcm_val;

    // Sum of first 'number_of_terms' multiples of 'lcm_val'
    int sum = lcm_val * number_of_terms * (number_of_terms + 1) / 2;

    // Apply the sign for inclusion-exclusion
    ans += sign * sum;
}

// Function to generate combinations and apply inclusion-exclusion principle
void generate_combinations(const vector<int> &arr, vector<int> &curr_combination, int start, int k, int sign)
{
    if (curr_combination.size() == k)
    {
        add_sum(curr_combination, sign);
        print(curr_combination);
        return;
    }

    for (int i = start; i < arr.size(); ++i)
    {
        curr_combination.push_back(arr[i]);                           // Adding element to combination
        generate_combinations(arr, curr_combination, i + 1, k, sign); // Recursive call
        curr_combination.pop_back();                                  // Removing element (backtracking)
    }
}

int32_t main()
{
    vector<int> curr = {};
    int sign = 1;

    for (int k = 1; k <= nums.size(); k++)
    {
        generate_combinations(nums, curr, 0, k, sign);
        sign = -sign; // Alternating sign for inclusion-exclusion
    }

    cout << ans << endl; // Output the final result
    return 0;
}
