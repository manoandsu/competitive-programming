#include <bits/stdc++.h>
using namespace std;

bool match(char a, char b) {
	return (a == 'B' && b == 'S') || (b ==  'B' && a == 'S') || (a == 'C' && b == 'F') || (b == 'C' && a == 'F');
}

int main() {
	string s;
	while (cin >> s){
		int ans = 0;
		stack<char> st;

		for(int i=0;i<s.size();i++){
			if (!st.empty() && match(s[i], st.top())){
				ans++;
				st.pop();
			}
			else st.push(s[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
