#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vis(1000, vector<int>(1000, 0));
bool isSafe(int i, int j, vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    if (i >= 0 and j >= 0 and i < n and j < m and mat[i][j] == 1 and vis[i][j] == 0)
        return true;
    return false;
}
void f(vector<vector<int>> &mat, int i, int j, int n, int m, string s)
{
    if (i == n and j == m)
    {
        cout << s << endl;
        return;
    }
    vis[i][j] = 1;
    // down
    if (isSafe(i + 1, j, mat))
    {
        f(mat, i + 1, j, n, m, s + "D");
    }
    // UP
    if (isSafe(i - 1, j, mat))
    {
        f(mat, i - 1, j, n, m, s + "U");
    }
    // Right
    if (isSafe(i, j + 1, mat))
    {
        f(mat, i, j + 1, n, m, s + "R");
    }
    // Left
    if (isSafe(i, j - 1, mat))
    {
        f(mat, i, j - 1, n, m, s + "L");
    }
    vis[i][j] = 0;
}
int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = mat.size();
    int m = mat[0].size();
    f(mat, 0, 0, n - 1, m - 1, "");
    return 0;
}