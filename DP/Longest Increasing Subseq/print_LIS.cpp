#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<int> dp(n + 1, 1), hash(n);

    int maxi = 1;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> v;
    v.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        v.push_back(nums[lastIndex]);
    }
    cout << endl;
    reverse(v.begin(), v.end());
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    cout << maxi << endl;

    return 0;
}