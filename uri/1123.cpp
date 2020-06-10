#include <bits/stdc++.h>
using namespace std;

#define INF 10000010

void dijkstra(int s, int r, const vector<vector<pair<int, int>>>& adj, vector<int>& d) {
    int n = adj.size();
    vector<int> p(n, -1);
    d.assign(n, INF);

    d[s] = 0;

    vector<bool> vis(n, false);
    for (int i=0;i<n;++i) {
        int v = -1;

        for (int j=0;j<n;++j) {
            if (!vis[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        bool isRoute = v <= r;

        if (d[v] == INF) break;

        vis[v] = true;

        for (auto edge : adj[v]) {
            int to = edge.first, weight = edge.second;

            if (isRoute && to != v + 1) continue;

            if (d[v] + weight < d[to]) {
                d[to] = d[v] + weight;
                p[to] = v;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n, m, c, k;
        cin >> n >> m >> c >> k;

        if (n == 0) break;

        vector<vector<pair<int, int>>> adj(n);
        vector<int> d;

        for (int i=0;i<m;++i) {
            int f, t, w;
            cin >> f >> t >> w;
            adj[f].push_back({t, w});
            adj[t].push_back({f, w});
        }

        dijkstra(k, c - 1, adj, d);

        cout << d[c-1] << "\n";
    }

    return 0;
}
