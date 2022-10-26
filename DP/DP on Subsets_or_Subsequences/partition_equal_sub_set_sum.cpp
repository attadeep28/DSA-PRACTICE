#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/partition-equal-subset-sum/
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets
such that the sum of elements in both subsets is equal.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

*/
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
    vector<int> arr = {1, 5, 11, 5};
    int sum = 0;
    int n = arr.size();
    for (auto it : arr)
        sum += it;

    if (sum & 1)
        cout << "FALSE";
    else
    {
        int k = sum / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        if (subsetSumToK(n - 1, arr, k, dp))
        {
            cout << "TRUE\n";
        }
        else
            cout << "FALSE\n";
    }

    return 0;
}