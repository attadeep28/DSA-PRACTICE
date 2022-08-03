//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    // Using DFS
    void findTopo(int vertex, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[vertex] = 1;
        for (auto it : adj[vertex])
        {
            if (!vis[it])
            {
                findTopo(it, vis, st, adj);
            }
        }
        st.push(vertex);
    }

private:
    // using bfs ( kahn's algorithm)
    void findTopoBFS(int V, vector<int> adj[])
    {
        vector<int> indegree(V + 1, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            ans.push_back(n);

            for (auto it : adj[n])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                findTopo(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends