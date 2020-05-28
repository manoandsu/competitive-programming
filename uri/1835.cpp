#include <bits/stdc++.h>

using namespace std;

int t, n, m, fr, to, ans;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> t;
    for (int k=1;k<=t;++k) {
        cin >> n >> m;
        
        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1);
        
        for(int i=0;i<m;++i) {
            cin >> fr >> to;
            adj[fr].push_back(to);
            adj[to].push_back(fr);
        }

        ans = 0;

        for(int i=1;i<=n;++i) {
            if (vis[i])
                continue;

            queue<int> q;
            q.push(i);

            while(!q.empty()) {
                int v = q.front();
                q.pop();

                for (int a : adj[v]) {
                    if (vis[a])
                        continue;

                    vis[a] = true;
                    q.push(a);
                }
            }
            ans++;
        }

        cout << "Caso #" << k << ": ";
        if (ans == 1)
            cout << "a promessa foi cumprida";
        else
            cout << "ainda falta(m) " << (ans-1) << " estrada(s)";
        cout << "\n";
    }
    return 0;
}
