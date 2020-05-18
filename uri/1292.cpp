#include <bits/stdc++.h>

using namespace std;

double f;
#define PI 3.14159265358979323846

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	
	while (!cin.eof()) {
		cin >> f;
		cout << (sin(108 * PI / 180) * f / (sin(63 * PI / 180))) << endl;
	}

	return 0;
}
