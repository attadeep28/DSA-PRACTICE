/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences

https://leetcode.com/problems/shortest-common-supersequence/

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = n, j = m;
        string ans = "";
        while (i > 0 and j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans = s1[i - 1] + ans;
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans = s1[i - 1] + ans;
                i--;
            }
            else
            {
                ans = s2[j - 1] + ans;
                j--;
            }
        }

        while (i > 0)
            ans = s1[i - 1] + ans, i--;
        while (j > 0)
            ans = s2[j - 1] + ans, j--;

        return ans;
    }
};

int main()
{
    string str1 = "abac", str2 = "cab";
    Solution sol;
    cout << sol.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}