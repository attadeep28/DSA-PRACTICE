
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int k, vector<int> &arr, int n)
    {
        long sum = 0;
        long maxi = 0;
        int i = 0, j = 0;

        while (j < n)
        {
            sum += arr[j];
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                maxi = max(maxi, sum);
                sum -= arr[i];
                i++, j++;
            }
        }

        return maxi;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        ;
        vector<int> Arr;
        for (int i = 0; i < N; ++i)
        {
            int x;
            cin >> x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K, Arr, N) << endl;
    }
    return 0;
}