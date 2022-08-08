#include <bits/stdc++.h>
using namespace std;
void printSubseq(int ind, int arr[], vector<int> &ds, int n)
{
    if (ind >= n)
    {
        if (ds.size() > 0)
            for (auto it : ds)
                cout << it << " ";
        else
            cout << "{}";
        cout << endl;

        return;
    }
    // Not pick
    printSubseq(ind + 1, arr, ds, n);
    // pick
    ds.push_back(arr[ind]);
    printSubseq(ind + 1, arr, ds, n);
    ds.pop_back();
}
// Sub-seq with target sum

void subSeq(int ind, int arr[], vector<int> &ds, int sum, int target, int n)
{
    if (ind >= n)
    {
        if (sum == target)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return;
        }
        else
            return;
    }

    // Pick
    sum += arr[ind];
    ds.push_back(arr[ind]);
    subSeq(ind + 1, arr, ds, sum, target, n);
    ds.pop_back();
    sum -= arr[ind];
    // Non Pick
    subSeq(ind + 1, arr, ds, sum, target, n);
}

bool isSeqPresent(int ind, int arr[], int target, int sum, int n)
{
    if (ind >= n)
    {
        if (sum == target)
            return true;
        return false;
    }
    // pick
    sum += arr[ind];
    if (isSeqPresent(ind + 1, arr, target, sum, n))
        return true;
    sum -= arr[ind];
    if (isSeqPresent(ind + 1, arr, target, sum, n))
        return true;
    return false;
}

// count subseq with target sum
int countSub(int ind, int arr[], int n, int target, int sum)
{
    if (ind >= n)
    {
        if (sum == target)
            return 1;
        return 0;
    }
    sum += arr[ind];
    int pick = countSub(ind + 1, arr, n, target, sum);
    sum -= arr[ind];
    int notPick = countSub(ind + 1, arr, n, target, sum);
    return pick + notPick;
}
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    cout << countSub(0, arr, n, 3, 0) << endl;
    return 0;
}