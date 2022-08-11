#include<bits/stdc++.h>
using namespace std;
/*
https://www.codingninjas.com/codestudio/problems/target-sum_4127362?leftPanelTab=0

You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding one of the symbols '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. You have to return the number of ways the target can be achieved.
*/

int countPartitionsUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken) ;
}

int countPartitions(int d, vector<int> &arr)
{
    int n = arr.size();
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - d < 0)
        return 0;
    if ((totSum - d) % 2 == 1)
        return 0;

    int s2 = (totSum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return countPartitionsUtil(n - 1, s2, arr, dp);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(target,arr);
}

int main(){
    return 0;
}