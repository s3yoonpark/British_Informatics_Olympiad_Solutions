#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ull;

string n; 

void solve() {
	if (stoull(n) < 11) {
		cout << 11 << '\n'; 
		return; 
	}
	int s = (int)(n.length()); 
	if (s%2 == 1) {
		string tmp = n.substr(0, 1+s/2); 
		int x = tmp.length(); 
		for (int i = x-2; i >= 0; --i) {
			tmp += tmp[i]; 	
		}
		if (stoull(tmp) > stoull(n)) {
			cout << tmp << '\n'; 
			return; 
		}
		tmp = n.substr(0, 1+s/2); 
		x = tmp.length(); 
		tmp = to_string(stoull(tmp)+1); 
		for (int i = x-2; i >= 0; --i) {
			tmp += tmp[i]; 
		}
		cout << tmp << '\n'; 
	} else {
		string tmp = n.substr(0, s/2); 
		int x = tmp.length(); 
		for (int i = x-1; i >= 0; --i) {
			tmp += tmp[i]; 
		}
		if (stoull(tmp) > stoull(n)) {
			cout << tmp << '\n'; 
			return; 
		}
		tmp = n.substr(0, s/2); 
		x = tmp.length(); 
		tmp = to_string(stoull(tmp)+1); 
		if (tmp.length() != x) {
			for (int i = x-1; i >= 0; --i) {
				tmp += tmp[i]; 
			}
			cout << tmp << '\n'; 
		} else {
			for (int i = x-1; i >= 0; --i) {
				tmp += tmp[i]; 
			}
			cout << tmp << '\n'; 
		}
	}
	return; 
}

int main() {
	cin >> n; 	
	solve(); 

	return 0; 
}
