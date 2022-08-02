#include <bits/stdc++.h>
using namespace std;
int V, E;
void dfs(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            dfs(it.first, vis, st, adj);
        }
    }
    // topo sort
    st.push(node);
}
void findDistance(int src, vector<pair<int, int>> adj[])
{
    vector<int> vis(V + 1, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    int inf = (int)1e9;
    vector<int> dis(V + 1, inf);
    dis[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dis[node] != inf)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])
                {
                    dis[it.first] = dis[node] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dis[i] != inf)
        {
            cout << src << " to " << i << " dist is: " << dis[i] << endl;
        }
        else
        {
            cout << src << " to " << i << " dist is: "
                 << "inf" << endl;
        }
    }
}
int main()
{

    cin >> V >> E;
    vector<pair<int, int>> adj[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    int src;
    cin >> src;
    findDistance(src, adj);

    return 0;
}
/*
5 7
0 1 10
0 4 20
1 2 30
1 3 40
1 4 50
2 3 60
3 4 70
0

 */