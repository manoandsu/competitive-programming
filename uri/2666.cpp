#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> dist(n+1);
    for(int i=1;i<=n;++i)
        cin >> dist[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<bool> vis(n+1, false);
    vector<int> p(n+1);
    vector<int> d(n+1, 0);

    for(int i=1;i<n;++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    int f = 1;
    stack<int> s;
    stack<int> lol;
    s.push(f);
    vis[f] = true;
    p[f] = -1;

    while(!s.empty()) {
        int v = s.top();
        s.pop();


        for (auto u : adj[v]) {
            if (vis[u.first]) continue;

            vis[v] = true;
            p[u.first] = v;
            s.push(u.first);
        }

        if (v != 1)
            lol.push(v);
        //cout << v << endl;
    }

    int ans = 0;
    while(!lol.empty()){
        int v = lol.top();
        int d = -1;

        for (int i=0;i<adj[p[v]].size();++i){
            if (adj[p[v]][i].first == v){
                d = adj[p[v]][i].second;
                break;
            }
        }
        int mover = ceil(dist[v] * 1.0f / c) * (2 * d);

        ans += mover;
        dist[p[v]] += dist[v];
        lol.pop();
    }

    cout << ans << endl;

    return 0;
}
