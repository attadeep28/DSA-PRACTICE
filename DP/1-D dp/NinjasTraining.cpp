#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
*/
int f(int day, int PrevTask, vector<vector<int>> arr, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != PrevTask)
            {
                maxi = max(maxi, arr[0][task]);
            }
        }
        return maxi;
    }
    if (dp[day][PrevTask] != -1)
        return dp[day][PrevTask];
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != PrevTask)
        {
            int points = arr[day][task] + f(day - 1, task, arr, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][PrevTask] = maxi;
}
int main()
{
    // vector<vector<int>> dp(n,vector<int>(4,0));
    return 0;
}