#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
        ex
        a[] = 1 3 5 4 2
        ind = 0 1 2 3 4

        step 1: start traversing from back and find first idx such that a[i] < a[i+1]
                ind1 = 1

        step 2: again start traversing from back and find a[ind2] > a[ind1]
                ind2 = 3

        step 3: swap(a[ind1],a[ind2])
                now our Array will be
            a[i]:    1 4 5 3 2
              i :    0 1 2 3 4

        step 4: reverse(a[ind1 + 1] to last)
            a[i]: 1 4 2 3 5
              i : 0 1 2 3 4
    */
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int k, l;
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
                break;
        }
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (l = n - 1; l >= k; l--)
            {
                if (nums[l] > nums[k])
                {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }

    // Brute force generate all permutaion
    // TC O(n!)
    void permute(vector<int> a, int l, int r)
    {
        // Base case
        if (l == r)
        {
            for (auto it : a)
                cout << it << " ";
            cout << endl;
        }
        else
        {
            // Permutations made
            for (int i = l; i <= r; i++)
            {

                // Swapping done
                swap(a[l], a[i]);

                // Recursion called
                permute(a, l + 1, r);

                // backtrack
                swap(a[l], a[i]);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> per = {1, 2, 3};
    sol.permute(per, 0, 2);

    // sol.nextPermutation(per);
    // for (auto it : per)
    //     cout << it << " ";
    return 0;
}