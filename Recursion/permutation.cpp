#include <bits/stdc++.h>
using namespace std;

/*
    TC : O(n! * n)
    SC : O(n) + O(n) for map
*/
void printP(vector<int> &arr, vector<int> &ds, unordered_map<int, bool> &mp)
{
    if (ds.size() == arr.size())
    {
        for (auto it : ds)
            cout << it << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp[i] == false)
        {
            mp[i] = true;
            ds.push_back(arr[i]);
            printP(arr, ds, mp);
            ds.pop_back();
            mp[i] = false;
        }
    }
}


/*
    TC : O(n! * n)
    SC : O(n) 
*/
void printPer(int ind, vector<int> &arr)
{
    if (ind == arr.size())
    {
        for (auto it : arr)
            cout << it << " ";
        cout << endl;
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        printPer(ind + 1, arr);
        swap(arr[ind], arr[i]);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    unordered_map<int, bool> mp;
    vector<int> ds;
    printP(arr, ds, mp);
    cout << endl << endl ;
    printPer(0, arr);
    return 0;
}