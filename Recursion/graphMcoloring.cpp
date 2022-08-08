//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node && graph[k][node] == 1 && color[k] == col)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int color[], int m, int n, bool graph[101][101])
    {
        if (node == n)
            return true;

        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, color, graph, n, i))
            {
                color[node] = i;
                if (solve(node + 1, color, m, n, graph))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }

public:
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // your code here
        int color[n] = {0};

        if (solve(0, color, m, n, graph))
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int N = 4;
    int m = 3;
    bool graph[101][101] = {
        (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)};
    Solution sol;
    cout << sol.graphColoring(graph, m, N);
    return 0;
}

// } Driver Code Ends