#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> merged;
    int ind1 = start, ind2 = mid + 1;
    int ind = 0;

    while (ind1 <= mid && ind2 <= end)
    {
        if (arr[ind1] <= arr[ind2])
        {
            merged.push_back(arr[ind1++]);
        }
        else
        {
            merged.push_back(arr[ind2++]);
        }
    }

    while (ind1 <= mid)
    {
        merged.push_back(arr[ind1++]);
    }
    while (ind2 <= end)
    {
        merged.push_back(arr[ind2++]);
    }

    for (int i = 0, j = start; i < merged.size(); i++, j++)
    {
        arr[j] = merged[i];
    }
}
void divide(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    divide(arr, start, mid);
    divide(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{

    vector<int> arr = {6, 3, 9, 5, 2, 8};
    int n = arr.size();

    divide(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}