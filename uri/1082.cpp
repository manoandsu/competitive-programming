#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

int atoi(char c) {
    return int(c) - 96;
}   

char itoc(int i) {
    return char(i + 96);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int k=1; k<=t; ++k) {
        int n, c;
        cin >> n >> c;

        vector<vector<int>> adj(n + 1);
        vector<bool> vis(n+1);

        for(int j=0;j<c;++j) {
            char from, to;
            cin >> from >> to;
            int from_i = atoi(from), to_i = atoi(to);
            adj[from_i].push_back(to_i);
            adj[to_i].push_back(from_i);
        }
        
        vector<vector<char>> ans;

        for (int i=1;i<=n;++i) {
            if (vis[i]) continue;

            stack<int> s;
            vector<char> temp;
            s.push(i);
            vis[i] = true;

            while (!s.empty()) {
                int v = s.top();
                s.pop();

                for (int u : adj[v]) {
                    if (vis[u]) continue;

                    vis[u] = true;
                    s.push(u);
                }

                temp.push_back(itoc(v));
            }

            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        cout << "Case #" << k << ":\n";

        for (auto v : ans){
            for (char l : v)
                cout << l << ",";
            cout << "\n";
        }

        cout << ans.size() << " connected components\n\n";
    }

    return 0;
}
