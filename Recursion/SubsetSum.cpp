#include <bits/stdc++.h>
using namespace std;
void printS(int ind, vector<int> &arr, int sum, vector<int> &sums)
{
    if (ind >= arr.size())
    {
        sums.push_back(sum);
        return;
    }

    // Pick
    sum += arr[ind];
    printS(ind + 1, arr, sum, sums);
    sum -= arr[ind];
    // Not Pick
    printS(ind + 1, arr, sum, sums);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> sums;
    printS(0, arr, 0, sums);
    sort(sums.begin(), sums.end());
    for(auto it: sums) cout << it << endl;
    return 0;
}