#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent[node]); // path compression
    }
    void Union(int a, int b) // by size
    {
        int parent_a = findParent(a);
        int parent_b = findParent(b);
        if (parent_a == parent_b)
        {
            return;
        }
        if (size[parent_a] < size[parent_b])
        {
            parent[parent_a] = parent_b;
            size[parent_b] += size[parent_a];
        }
        else
        {
            parent[parent_b] = parent_a;
            size[parent_a] += size[parent_b];
        }
    }
};
int main()
{ // kruskal Algo
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> edges;
    DSU dsu(V);
    for (int i = 0; i < E; i++)
    {
        int wt, u, v;
        cin >> wt >> u >> v;
        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end());
    int total = 0;
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (dsu.findParent(u) == dsu.findParent(v))
        {
            continue;
        }
        else
        {
            dsu.Union(u, v);
            cout << u << " " << v << endl;
            total += wt;
        }

    }
    cout << "Minimum Cost:"<<total<<endl;

    return 0;
}