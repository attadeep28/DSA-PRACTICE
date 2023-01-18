#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector<int> ans;

        int i = 0, j = 0;
        while (j < n)
        {
            while (!dq.empty() && arr[j] > dq.back())
                dq.pop_back();

            dq.push_back(arr[j]);

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {

                ans.push_back(dq.front());

                if (arr[i] == dq.front())
                    dq.pop_front();

                i++, j++;
            }
        }
        return ans;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
