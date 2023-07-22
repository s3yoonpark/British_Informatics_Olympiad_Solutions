#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ull;

int l; 
string p; 
bool available[26];  
ull saved[524287 + 1][20]; 

void adjust() {
	memset(available, 0, sizeof(available)); 
	for (int i = 0; i < l; ++i) available[i] = 1; 
	for (char c : p) available[c-'A'] = 0; 
	for (int i = 0; i < p.length(); ++i) {
		for (int j = i+1; j < p.length(); ++j) {
			if (p[j] > p[i]) {
				for (int k = p[j]+1; k < p[j] + l; ++k) {
					available[k-'A'] = 0; 	
				}
			}
		}
	}
	return; 
}

ull convert() {
	ull res = 0; 
	for (int i = 0; i < 26; ++i) {
		if (available[i]) {
			res ^= (1<<i); 
		}
	}
	return res; 
}

ull Count() {
	ull total = 0; 
	if (p.length() == l) {
		cout << p << '\n'; 
		return 1; 
	}
	ull test = saved[convert()][p.length()];
	if (test) {
		return test; 
	}
	int num = count(available, available+26, 1); 
	if (num + p.length() < l) return 0; 
	for (int i = 0; i < 26; ++i) {
		if (available[i]) {
			p += (char)('A'+i); 
			adjust(); 
			total += Count(); 
			p = p.substr(0, p.length()-1); 
			adjust(); 
		}
	}
	return saved[convert()][p.length()] = total; 
}

void solve() {
	adjust(); 
	cout << Count() << '\n'; 
	return; 
}

int main() {
	cin >> l >> p; 	
	solve(); 

	return 0; 
}
