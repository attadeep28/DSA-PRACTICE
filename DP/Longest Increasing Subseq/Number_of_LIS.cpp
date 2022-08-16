#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
                {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int maxx = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxx)
                ans += cnt[i];
        }
        return ans;
    }
};

int main()
{
    /*
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].*/

    vector<int> nums = {1, 3, 5, 4, 7};
    Solution sol;
    cout << sol.findNumberOfLIS(nums);
}