#include <bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ull;

string n; 

void solve() {
	if (stoull(n) < 11) {
		//cout << 11 << '\n'; 
		n = 11; 
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
			//cout << tmp << '\n'; 
			n = tmp; 
			return; 
		}
		tmp = n.substr(0, 1+s/2); 
		x = tmp.length(); 
		tmp = to_string(stoull(tmp)+1); 
		for (int i = x-2; i >= 0; --i) {
			tmp += tmp[i]; 
		}
		//cout << tmp << '\n'; 
		n = tmp; 	
	} else {
		string tmp = n.substr(0, s/2); 
		int x = tmp.length(); 
		for (int i = x-1; i >= 0; --i) {
			tmp += tmp[i]; 
		}
		if (stoull(tmp) > stoull(n)) {
			//cout << tmp << '\n'; 
			n = tmp; 
			return; 
		}
		tmp = n.substr(0, s/2); 
		x = tmp.length(); 
		tmp = to_string(stoull(tmp)+1); 
		if (tmp.length() != x) {
			for (int i = x-1; i >= 0; --i) {
				tmp += tmp[i]; 
			}
			//cout << tmp << '\n'; 
			n = tmp; 
		} else {
			for (int i = x-1; i >= 0; --i) {
				tmp += tmp[i]; 
			}
			//cout << tmp << '\n'; 
			n = tmp; 
		}
	}
	return; 
}

int main() {
	n = "11"; 
	ull prev = stoull(n); 
	//ull end = 9999999999999999999; 
	ull end = 999999;
	ull diff = 0; 
	while (1) {
		solve(); 
		if (stoull(n) > end) break; 
		diff = max(diff, stoull(n) - prev); 
		prev = stoull(n); 
	}
	cout << diff << '\n'; 

	// number of 9's     diff 
	// 2 11 
	// 4 110 
	// 6 1100
	// 11 + (n/2)-1 * 0
	// 20 -> 11000000000



	return 0; 
}
