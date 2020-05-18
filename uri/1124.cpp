#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int l, c, r1, r2;
	while (1){
		cin >> l >> c >> r1 >> r2;
		if (l == c && r1 == r2 && l == r1 && l == 0) return 0;
		
		int m = max(r1, r2) * 2;
		if (m > l || m > c){
			cout << "N\n";
			continue;
		}
		double hip = sqrt(pow(l-r1-r2, 2) + pow(c-r1-r2, 2));

		if (hip >= r1+r2)
			cout << "S\n";
		else
			cout << "N\n";
	}
	return 0;
}
