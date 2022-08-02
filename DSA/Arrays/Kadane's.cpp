// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    long long maxSubarraySum(int arr[], int n)
    {

        // Your code here
        long long maxi = INT_MIN;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum < 0)
            {
                maxi = max(maxi, sum);
                sum = 0;
            }
            sum += arr[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends