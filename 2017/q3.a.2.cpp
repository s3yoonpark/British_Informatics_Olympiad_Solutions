#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;  

const int mxW = 25; 
const int mxN = 25; 
const int mxP = 5; 
int p, i, n, w; 
ull dp[mxW+1][mxN+1]; 
ull dp2[mxP+1][mxN+1];

void solve() {
	dp[0][0] = 1; 
	for (int k = 1; k <= i; ++k) {
		for (int x = 1; x <= w; ++x) {
			for (int y = 1; y <= n; ++y) {
				if (x-k >= 0) dp[x][y] += dp[x-k][y-1]; 
			}
		}
	}
	dp2[0][0] = 1; 
	for (int x = 1; x <= p; ++x) {
		for (int y = 1; y <= n; ++y) {
			for (int k = 1; k <= n; ++k)  {
				if (y-k >= 0) dp2[x][y] += dp2[x-1][y-k] * dp[w][k]; 
			}
		}
	}
	cout << dp2[p][n] << '\n'; 
	
	return; 
}

int main() {
	cin >> p >> i >> n >> w; 
	solve(); 

	return 0; 
}
