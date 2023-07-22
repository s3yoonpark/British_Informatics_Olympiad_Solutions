#include <bits/stdc++.h>
using namespace std;

char table[10][10]; 
string start = ""; 
char lst[3] = {'R', 'G', 'B'}; 

string solve() {
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
	string res = ""; 
	for (int i = 0; i < 8; ++i) {
		res += table[7][i]; 
	}
	return res;
}

void gen() {
	if (start.length() == 9) {
		// processed
		if (solve() == "RRGBRGBB") {
			cout << start << '\n'; 
		}
		return ; 
	}
	for (int i = 0; i < 3; ++i) {
		start += lst[i]; 
		gen(); 
		start = start.substr(0, start.length()-1); 
	}	
	return; 
}


int main() {
	gen(); 

	return 0; 
}
