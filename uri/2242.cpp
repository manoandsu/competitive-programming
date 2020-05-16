#include <bits/stdc++.h>

using namespace std;

int n, m, ans;

bool isPalindrome(string s) {
	int i = 0, j=s.size()-1;

	while(i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}

	return true;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string s, s2;

	cin >> s;
	for(int i =0;i<s.size();++i){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			s2.push_back(s[i]);
	}

	cout << (isPalindrome(s2) ? "S" : "N") << endl;
	return 0;
}
