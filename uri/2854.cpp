#include <bits/stdc++.h>

using namespace std;

int m, n;
string f, temp, t;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> m >> n;

	unordered_map<string, vector<string>> adj;
	unordered_map<string, bool> vis;

	for(int i=0;i<n;++i) {
		cin >> f >> temp >> t;

		adj[f].push_back(t);
		adj[t].push_back(f);
	}
	
	int ans = 0;
	for(auto fam : adj) {
		if (vis[fam.first])
			continue;

		queue<string> q;
		q.push(fam.first);
		vis[fam.first] = true;

		while(!q.empty()) {
			string v = q.front();
			q.pop();

			for (auto to : adj[v]) {
				if (vis[to])
					continue;

				q.push(to);
				vis[to] = true;
			}
		}
		ans++;
	}

	cout << ans << endl;
	return 0;
}
