#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void findCom(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind and arr[i - 1] == arr[i])
                continue;
            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);
            findCom(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back(); // backTrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCom(0, target, candidates, ds, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> ans = sol.combinationSum2(arr, target);
    for (auto it : ans)
    {
        for (auto el : it)
            cout << el << " ";
        cout << endl;
    }
    return 0;
}