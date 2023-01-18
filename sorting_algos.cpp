#include <bits/stdc++.h>
using namespace std;
void print(int a[], int n)
{
    cout << "\nArray is: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubble_sort(int arr[], int n)
{
    // TC : O(n*n) number of comparisons (n-1)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    print(arr, n);
}

void selection_sort(int arr[], int n)
{
    // in selection sort we bring the smallest element in the front

    // TC = O(n^2)
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallest] > arr[j])
                swap(arr[smallest], arr[j]);
        }
    }

    print(arr, n);
}

void insertion_sort(int arr[], int n)
{
    /*
        insert an element form unsorted array to its correct position in sorted array
    */
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    print(arr, n);
}

int main()
{
    int arr[] = {7, 8, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    return 0;
}