#include <bits/stdc++.h>
using namespace std;
/*
https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
Partition a set into two subsets such that the difference of subset sums is minimum

*/
int main()
{
    vector<int> arr = {8, 6, 5};

    int k = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();
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

    int total_sum = k;
    int miniDif = INT_MAX;
    for (int i = 0; i <= total_sum; i++)
    {
        if (dp[n - 1][i] == 1)
        {
            int s1 = i;
            int s2 = total_sum - i;
            miniDif = min(miniDif, abs(s2 - s1));
        }
    }
    cout << miniDif << endl;
    return 0;
}