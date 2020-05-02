#include <bits/stdc++.h>
using namespace std;

int x, y, px = 0, py = 0, dir = 0;
char tmap[101][101];
bool visited[101][101];

void move() {
    if (dir == 0) px--;
    else if (dir == 1) py++;
    else if (dir == 2) px++;
    else if (dir == 3) py--;
}

void changeDir() {
    if (tmap[px][py] == '^') dir = 0;
    else if (tmap[px][py] == '>') dir = 1;
    else if (tmap[px][py] == 'v') dir = 2;
    else if (tmap[px][py] == '<') dir = 3;
}
char findTreasure() {
    while (true) {
        changeDir();
        move();

        if (tmap[px][py] == '*') return '*';
        
        if (px < 0 || py < 0 || px >= x || py >= y || (visited[px][py] && tmap[px][py] != '.'))
            return '!';
        
        visited[px][py] = true;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> y >> x;
    string s;

    for (int i=0;i<x;++i) {
        cin >> s;
        for (int j=0; j<y; ++j)
            tmap[i][j] = s[j];
    }
    
    cout << findTreasure() << endl;

    return 0;
}
