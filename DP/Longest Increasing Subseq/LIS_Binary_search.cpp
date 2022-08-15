#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();

    vector<int> tem;
    int len = 1;
    tem.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > tem.back())
        {
            tem.push_back(nums[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(tem.begin(), tem.end(), nums[i]) - tem.begin();
            tem[ind] = nums[i];
        }
    }

    cout << len << endl;
    return 0;
}