#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(V + 1, (int)1e9);

    cout << "Enter Src:";
    int src;
    cin >> src;
    queue<int> q;

    dis[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dis[it] > 1 + dis[node])
            {
                q.push(it);
                dis[it] = 1 + dis[node];
            }
        }
    }

    for (auto i = 0; i < V; i++)
    {
        cout << src << " to " << i << " dist is " << dis[i] << endl;
    }
    return 0;
}