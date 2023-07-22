#include <bits/stdc++.h> 

using namespace std; 

int main() {
	string ins; 
	cin >> ins; 
	int l = 1; 
	int m = 0; 
	int r = 0; 
	int s = 1; 
	pair<int,int> cur = make_pair(l+r, m+s); 

	for (char i : ins) {
		if (i == 'L') {
			l = cur.first; 
			m = cur.second; 
		} else {
			r = cur.first;
			s = cur.second; 
		}
		cur = make_pair(l+r, m+s); 
	}
	cout << cur.first << " / " << cur.second << "\n"; 

	return 0; 
}
