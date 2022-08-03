
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // USING DFS
    bool dfs(int vertex, vector<int> adj[], vector<int> &vis, int par)
    {
        vis[vertex] = 1;

        for (auto child : adj[vertex])
        {
            if (!vis[child])
            {
                if (dfs(child, adj, vis, vertex))
                    return 1;
            }
            else if (child != par)
                return 1;
        }

        return false;
    }

    // USING BFS
    bool bfs(int vertex, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int, int>> q;
        vis[vertex] = 1;
        q.push({vertex, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (par != it)
                    return 1;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {

        vector<int> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, -1))
                    return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends