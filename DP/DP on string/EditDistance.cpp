#include <bits/stdc++.h>
/* https://leetcode.com/problems/edit-distance/
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/
using namespace std;
class Solution
{
private:
    // memoization
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        else
        {

            int insert = 1 + f(i, j - 1, s1, s2, dp);
            int replace = 1 + f(i - 1, j - 1, s1, s2, dp);
            int Delete = 1 + f(i - 1, j, s1, s2, dp);
            return dp[i][j] = min(insert, min(replace, Delete));
        }
    }

public:
    int minDistance(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {

                    int insert = 1 + dp[i][j - 1];
                    int replace = 1 + dp[i - 1][j - 1];
                    int Delete = 1 + dp[i - 1][j];
                    dp[i][j] = min(insert, min(replace, Delete));
                }
            }
        }

        return dp[n][m];
    }
};