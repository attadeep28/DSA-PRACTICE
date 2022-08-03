#include <bits/stdc++.h>
using namespace std;
void print(vector<int> a1, vector<int> a2)
{
    for (auto it : a1)
        cout << it << " ";
    for (auto it : a2)
        cout << it << " ";
    cout << endl;
}

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
// Approach 3 : gap method  TC: O((n+m)*log(n+m))       SC: O(1)
void merge(int *arr1, int *arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m)
        {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}
int main()
{
    vector<int> a1 = {1, 4, 7, 8, 10};
    vector<int> a2 = {2, 3, 9};

    int n = a1.size();
    int m = a2.size();
    // Approach 1 : TC O(n + m + n*logn) SC O(n + m)

    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(a1[i]);
    for (int i = 0; i < m; i++)
        ans.push_back(a2[i]);
    sort(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    // Approach 2 : TC O(n*m) SC O(1) // kind of insertion sort
    for (int i = 0; i < n; i++)
    {
        if (a1[i] > a2[0])
        {
            swap(a1[i], a2[0]);
            for (int j = 0; j < m - 1; j++)
            {
                if (a2[j] > a2[j + 1])
                {
                    swap(a2[j], a2[j + 1]);
                }
            }
        }
    }
    print(a1, a2);

    return 0;
}