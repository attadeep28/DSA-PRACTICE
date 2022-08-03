//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool checkCycle(int vertex, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
    {
        vis[vertex] = 1;
        pathVis[vertex] = 1;
        for (auto it : adj[vertex])
        {
            if (!vis[it])
            {
                if (checkCycle(it, vis, pathVis, adj))
                    return true;
            }
            else if (pathVis[it])
                return true;
        }

        pathVis[vertex] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V + 1, 0);
        vector<int> pathVis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (checkCycle(i, vis, pathVis, adj))
            {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends