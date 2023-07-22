#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull; 

ull n;  
string lst = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 

ull dp[37][36];

void solve() {
	string ans = ""; 
	ull l = 1; 
	while (1) {
		//bool added = 0; 
		for (char c : lst) {
			// starting letter 
			ull t = dp[l][lst.find(c)]; 
			if (n > t) {
				n -= t; 
			} else {
				ans += c; 
				//added = 1; 	
				while (ans.length() != l) {
					
				}
				break; 
			}
		}
		//if (!added) ++l; 
		if (!n) break; 
	}
	cout << ans << '\n'; 

	return; 
}

int main() {
	for (int i = 0; i < 36; ++i) dp[1][i] = 1; 	
	for (int i = 2; i <= 36; ++i) {
		for (int j = 0; j < 36; ++j) {
			for (int k = j+1; k < 36; ++k) {
				dp[i][j] += dp[i-1][k]; 

			}
		}
	}
	cin >> n; 
	solve(); 

	return 0; 
}
