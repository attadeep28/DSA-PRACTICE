#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int n = arr.size();
    int leftMini = arr[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - leftMini;
        maxProfit = max(cost, maxProfit);
        leftMini = min(arr[i], leftMini);
    }

    cout << maxProfit << endl;
    return 0;
}