#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, newi, newj;
	int arr[4][4];
	bool u, r, d, l, end;
	string ans;

	cin >> n;
	while(n--) {
		u = r = d = l = end = false;

		ans = "";

		for(int i =0;i<4;i++)
			for(int j=-0;j<4;j++){
				cin >> arr[i][j];
				if (arr[i][j] == 2048)
					end = true;
			}

		if (end) {
			cout << "NONE" << endl;
			continue;
		}

		for(int i =0;i<4;i++){
			for(int j=0;j<4;j++){
				if (arr[i][j] != 0){
					newj = min(3, j+1);
					if (newj != j && (arr[i][newj] == 0 || arr[i][j] == arr[i][newj])) r = true;
					newj = max(0, j-1);
					if (newj != j && (arr[i][newj] == 0 || arr[i][j] == arr[i][newj])) l = true;
					newi = min(3, i+1);
					if (newi != i && (arr[newi][j] == 0 || arr[i][j] == arr[newi][j])) d = true;
					newi = max(0, i-1);
					if (newi != i && (arr[newi][j] == 0 || arr[i][j] == arr[newi][j])) u = true;
				}
			}
		}

		if(d)
			ans += "DOWN";

		if(l)
			ans += (ans != "" ? " LEFT" : "LEFT");

		if(r)
			ans += (ans != "" ? " RIGHT" : "RIGHT");

		if(u)
			ans += (ans != "" ? " UP" :"UP");

		if (ans == "")
			cout << "NONE" << endl;
		else
			cout << ans << endl;
	}
	
 	return 0;
} 
