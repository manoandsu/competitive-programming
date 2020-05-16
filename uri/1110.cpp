#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	while(1){
		cin >> n;
    
		if (n == 0)
			break;
      
		queue<int> q;
		for (int i=1; i<=n; ++i)
			q.push(i);

		cout << "Discarded cards: ";
		while(q.size() > 1) {
			cout << q.front() << (q.size() == 2 ? "" : ", ");
			q.pop();
			q.push(q.front());
			q.pop();
		}
    
		cout << "\n";
		cout << "Remaining card: " << q.front() << "\n";
	}
    return 0;
}
