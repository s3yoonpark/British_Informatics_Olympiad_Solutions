#include <bits/stdc++.h> 

using namespace std; 

vector<int> v (5, 0); 

int comb(int n, int r) {
	int prod = 1; 
	for (int i = 1; i <= n; ++i) {
		prod *= i; 
	}
	for (int i = 1; i <= r; ++i) {
		prod /= i; 
	}
	for (int i = 1; i <= n-r; ++i) {
		prod /= i; 
	}
	return prod;
}

int solve() {
	int c = 0; 
	// identical 
	set<int> t (v.begin(), v.end()); 	
	for (int i : t) {
		int co = count(v.begin(), v.end(), i);
		if (co > 1) {
			c += comb(co, 2); 
		}
	}
	int k = 0; 
	for (int i = 0; i < 32; ++i) {
		int sum = 0; 
		for (int j = 0; j < 5; ++j) {
			if ((k & (1 << j)) == (1 << j)) {
				sum += v[j]; 
			}
		}
		if (sum == 15) {
			++c; 
		}
		++k; 
	}
	
	return c; 
}

int main() {
	for (int i = 0; i < 5; ++i) {
		cin >> v[i]; 
	}
	cout << solve() << "\n"; 

	return 0; 
}
