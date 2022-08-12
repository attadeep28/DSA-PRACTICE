#include <bits/stdc++.h>
using namespace std;

/*
    https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
    s1 = abcd   s2=anc
    to convert s1 into s2
    operation 2 deletion and 1 insertion
    n = s1.size()  m = s2.size()

    mini operation = n + m - 2 * len(lcs)

*/
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == ptr[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcsLen = dp[n][m];

    return (n + m - 2 * lcsLen);
}

int main()
{
    string s1 = "abcd", s2 = "anc";
    cout << canYouMake(s1, s2) << endl;
    return 0;
}