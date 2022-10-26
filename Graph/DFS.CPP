
#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    vector<int> dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans)
    {

        vis[node] = 1;
        ans.push_back(node);

        for (auto child : adj[node])
        {
            if (vis[child] == 0)
            {
                dfs(child, vis, adj, ans);
            }
        }
        return ans;
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V + 1, 0);
        vis[0] = 1;
        vector<int> traversal;
        return dfs(0, vis, adj, traversal);
    }
};

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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


