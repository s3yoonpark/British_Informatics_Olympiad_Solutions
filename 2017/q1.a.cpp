#include <bits/stdc++.h>
using namespace std;

char table[10][10]; 
string start; 

void solve() {
	for (int i = 0; i < start.length(); ++i) {
		table[start.length()-1][i] = start[i]; 
	}
	for (int i = start.length()-2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			if (table[i+1][j] == table[i+1][j+1]) {
				table[i][j] = table[i+1][j]; 
			} else {
				vector<char> v = {'R','G','B'}; 
				v.erase(find(v.begin(), v.end(), table[i+1][j])); 
				v.erase(find(v.begin(), v.end(), table[i+1][j+1])); 
				table[i][j] = v[0]; 
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << table[i][j]; 
		}
		cout << '\n'; 
	}
	cout << table[0][0] << '\n'; 
}

int main() {
	cin >> start; 	
	solve(); 

	return 0; 
}
