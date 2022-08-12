#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

sol :
    step 1: find longest palindromic string in s
    step 2: number of insertion required will be 
        (length of string - longest palindromic string in s)

*/
class Solution
{
public:
    int minInsertions(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (s[i - 1] == rev[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int maxLen = dp[n][n];

        return n - maxLen;
    }
};