/*
https://leetcode.com/problems/longest-string-chain/

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
*/

#include <bits/stdc++.h>
using namespace std;
bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
class Solution
{
private:
    bool check(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0;
        int second = 0;
        while (first < s1.size())
        {
            if (second < s2.size() && s1[first] == s2[second])
            {
                second++, first++;
            }
            else
                first++;
        }

        if (first == s1.size() && second == s2.size())
            return true;
        return false;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n + 1, 1);

        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (check(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }

        return maxi;
    }
};

int main()
{
    return 0;
}