#include <bits/stdc++.h>
using namespace std;

void topSort(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            topSort(it, vis, adj, st);
        }
    }
    st.push(node);
}
void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    cout << node << " ";

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj);
        }
    }
 
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    vector<int> vis(V + 1, 0);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // Kosarajus Algorithm

    // Step 1: Sort All Node in Order Of Finishing Time (Topo - sort)
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            topSort(i, vis, adj, st);
        }
    }

    // Step 2: Transpose The Graph
    vector<int> transpose[V + 1];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    // Step 3: Do dfs A/c to finishing Time (do dfs on trnaspose graph A/c Stack order)
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            dfs(node, vis, transpose);
               cout << endl;
        }
    }
    return 0;
}

/*
5 5
0 1
1 2
2 0
1 3
3 4
*/