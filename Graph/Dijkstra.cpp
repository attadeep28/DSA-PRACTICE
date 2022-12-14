#include <bits/stdc++.h>
using namespace std;
int V, E;

int main()
{
    cin >> V >> E;
    vector<pair<int, int>> adj[V + 1];
    for (auto i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    cout << "Enter Src:";
    int src, dest;
    cin >> src;
    cout << "Enter Destination:";
    cin >> dest;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distTo(V + 1, INT_MAX), path(V + 1); // 1-indexed array for calculating shortest paths;
    for (int i = 0; i <= V; i++)
    {
        path[i] = i;
    }
    distTo[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edjWt = it.second;
            if (distTo[adjNode] > dis + edjWt)
            {
                path[adjNode] = node;
                distTo[adjNode] = dis + edjWt;
                pq.push({distTo[adjNode], adjNode});
            }
        }
    }

    vector<int> spath;
    spath.push_back(dest);
    int node = path[dest];
    while (path[node] != node)
    {
        spath.push_back(node);
        node = path[node];
    }
    spath.push_back(src);
    reverse(spath.begin(), spath.end());

    for (auto it : spath)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "The distances from source, " << src << ", are : \n";
    for (int i = 0; i < V; i++)
        cout << "from" << src << "to" << i << ": " << distTo[i] << " " << endl;
    cout << "\n";
    return 0;
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
7 8 7
7 6 1
2 8 2
8 6 6
2 5 4
6 5 2
2 3 7
3 5 14
5 4 10
3 4 9
0

*/