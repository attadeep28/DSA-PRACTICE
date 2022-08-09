#include <bits/stdc++.h>
/*
https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
*/
using namespace std;

// Memoiaztion TC O(N*K) SC (N*K) + O(N)
bool subsetSumToK(int ind, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (ind == 0)
        return k == arr[0];

    if (dp[ind][k] != -1)
        return dp[ind][k];

    bool notTake = subsetSumToK(ind - 1, arr, k, dp);
    bool Take = 0;
    if (arr[ind] <= k)
    {
        Take = subsetSumToK(ind - 1, arr, k - arr[ind], dp);
    }

    return dp[ind][k] = Take or notTake;
}
int main()
{
    vector<int> arr = {1,2,3,4};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp1(n, vector<int>(k + 1, -1));

    cout << subsetSumToK(n - 1, arr, k, dp1) << endl;

    // Tabulation
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }
    cout << dp[n - 1][k] << endl;
    return 0;
}