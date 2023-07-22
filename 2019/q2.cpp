#include <bits/stdc++.h> 

using namespace std; 

int main() {
	int t; 
	cin >> t;
	string ins; 
	cin >> ins; 
	int m; 
	cin >> m; 
	int x = 0; 
	int y = 0; 
	int dir = 0; 
	vector<pair<int,int>> trails; 
	for (int i = 0; i < m; ++i) {
		char cur = ins[i % ins.length()];	
		trails.push_back(make_pair(x,y));
		if (cur == 'L') {
			--dir; 
			dir %= 4; 
		} else if (cur == 'R') {
			++dir; 
			dir %= 4; 
		}
		if (dir < 0) {
			dir += 4; 
		}
		
		bool ok = 1; 
		int count = 0; 
		while (1) {
			int tx = x; 
			int ty = y; 
			if (dir == 0) {
				++ty; 
			} else if (dir == 1) {
				++tx; 
			} else if (dir == 2) {
				--ty; 
			} else {
				--tx; 
			}
			if (find(trails.begin(), trails.end(), make_pair(tx, ty)) == trails.end()) {
				x = tx; 
				y = ty; 
				break;
			} else {
				++dir; 
				dir %= 4; 
				++count; 
				if (count == 4) {
					ok = 0; 
					break; 
				} 
			}
		}
		if (!ok) break; 
		if (trails.size() == t) {
			trails.erase(trails.begin()); 
		}
	}
	
	cout << "(" << x << ", " << y << ")" << "\n";

	return 0; 
}
