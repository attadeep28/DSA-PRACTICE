
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int node, vector<int> adj[])
    {
        vector<int> bfsTraversal;
        queue<int> q;
        q.push(0);
        vector<int> vis(node + 1, 0);
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            bfsTraversal.push_back(n);
            for (auto child : adj[n])
            {
                if (vis[child] == 0)
                {
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        return bfsTraversal;
    }
};


int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
