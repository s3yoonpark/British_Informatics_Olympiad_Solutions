#include <bits/stdc++.h>
using namespace std;

char table[10][10]; 
string start = ""; 
char lst[3] = {'R', 'G', 'B'}; 
bool ok = 1;

char solve() {
	memset(table, ' ', sizeof(table)); 
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
	return table[0][0]; 
}

void gen(int l) {
	if (start.length() == l) {
		// processed
		char supposed; 
		if (start[0] == start[start.length()-1]) {
			supposed = start[0]; 
		} else {
			vector<char> v = {'R','G','B'}; 
			v.erase(find(v.begin(), v.end(), start[0])); 
			v.erase(find(v.begin(), v.end(), start[start.length()-1])); 
			supposed = v[0]; 
		}
		ok &= (supposed == solve()); 
		return ; 
	}
	for (int i = 0; i < 3; ++i) {
		start += lst[i]; 
		gen(l); 
		start = start.substr(0, start.length()-1); 
	}	
	return; 
}


int main() {
	for (int l = 5; l <= 100; ++l) {
		ok = 1;
		gen(l); 
		if (ok) {
			cout << l << '\n'; 
			break; 
		}
	}

	return 0; 
}
