#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}
int main()
{
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2};
    quickSort(arr, 0, arr.size() - 1);

    for (auto it : arr)
        cout << it << " ";
    return 0;
}