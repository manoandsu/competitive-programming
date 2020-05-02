#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int, int> p;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<string> vec(n);
    
    for (int i=0;i<n;++i) {
        cin >> vec[i];
    }

    for (int j=0;j<m;++j) {
        if (vec[0][j] == 'o'){
            p = {0, j};
            break;
        }
    }

    queue<pair<int, int> > q;
    q.push(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p.first + 1 < n && (vec[p.first + 1][p.second]) == '#'){
            if (p.second - 1 >= 0 && (vec[p.first][p.second - 1] == '.')){
                vec[p.first][p.second-1] = 'o';
                q.push({p.first, p.second-1});
            }
            
            if (p.second + 1 < m && (vec[p.first][p.second + 1] == '.')){
                vec[p.first][p.second+1] = 'o';
                q.push({p.first, p.second+1});
            }
        }

        if (p.first + 1 < n && vec[p.first + 1][p.second] == '.'){
            vec[p.first+1][p.second] = 'o';
            q.push({p.first+1, p.second});
        }
    }

    for (string v : vec)
        cout << v << endl;
    return 0;
}
