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
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    printSubseq(0, arr, ds, n);
    return 0;
}