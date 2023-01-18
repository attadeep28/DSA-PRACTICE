#include <bits/stdc++.h>
using namespace std;
// int arr[10000000];
// int n = 0;

// void insert(int value)
// {
//     if (n == 0)
//     {
//         n += 1;
//         arr[n] = value;
//         return;
//     }
//     n = n + 1;
//     arr[n] = value;
//     int i = n;

//     while (i > 1)
//     {
//         int parent = i / 2;

//         if (arr[parent] < arr[i])
//         {
//             swap(arr[parent], arr[i]);
//             i = parent;
//         }
//         else
//             return;
//     }
// }

// void Delete()
// {
//     (arr[1] = arr[n]);
//     n = n - 1;

//     int i = 1;
//     while (i < n)
//     {
//         int leftChild = arr[2 * i];
//         int rightChild = arr[2 * i + 1];

//         int largest = leftChild > rightChild ? 2 * i : 2 * i + 1;

//         if (arr[i] < arr[largest])
//         {
//             swap(arr[i], arr[largest]);
//             i = largest;
//         }
//         else
//             return;
//     }
// }

int arr[5] = {53, 51, 6, 77, 3};
void heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l < n && arr[l] > arr[largest])
    {

        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {

        largest = r;
    }

    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(n, largest);
    }
}
int main()
{

    heapify(5, 5);

    for (int i = 5 / 2; i>=0; i--)
    {
        heapify(5, i);
    }
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}