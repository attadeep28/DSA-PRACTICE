#include <bits/stdc++.h>
using namespace std;
// Memoiatio
int f(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int firstStep = f(ind - 1, arr, dp) + abs(arr[ind] - arr[ind - 1]);
    int secondStep = INT_MAX;
    if (ind > 1)
    {
        secondStep = f(ind - 2, arr, dp) + abs(arr[ind] - arr[ind - 2]);
    }
    return dp[ind] = min(firstStep, secondStep);
}
int main()

{
    int n;
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    n = arr.size();
    // memoization
    vector<int> dp1(n + 1, -1);
    cout << f(n - 1, arr, dp1) << endl;

    // Tabulation
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int firstStep = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int secondStep = INT_MAX;
        if (i > 1)
        {
            secondStep = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        }

        dp[i] = min(firstStep, secondStep);
    }
    cout << dp[n - 1] << endl;


    // Space Optimization
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int firstStep = prev + abs(arr[i] - arr[i - 1]);
        int secondStep = INT_MAX;
        if (i > 1)
        {
            secondStep = prev2 + abs(arr[i] - arr[i - 2]);
        }

        int curi = min(firstStep, secondStep);
        prev2 = prev;
        prev = curi;
    }
    cout << prev << endl;

    return 0;
}