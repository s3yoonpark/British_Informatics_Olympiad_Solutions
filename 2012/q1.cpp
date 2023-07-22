#include <bits/stdc++.h> 

using namespace std; 

vector<int> ps; 
set<int> distinct_p; 

bool check(int n) {
	if (n == 1) return false;
   	if (n == 2 || n == 3 || n == 5 || n == 7) return true; 
	if (n%2 == 0) return false; 

	for (int i = 3; i <= pow(n, 0.5); i++) {
		if (n % i == 0) return false;
	}	
	
	return true;
}




void solve(int n) {
	if (n == 1) return;
	for (int i : ps) {
		if (n % i == 0) {
			distinct_p.insert(i); 
			return solve(n/i); 
		}
	}
	return;  	
}



int main() {
	int n;
	cin >> n; 
	for (int i = 2; i <= n; i++) {
		if (check(i)) {
			ps.push_back(i); 
		}
	}
	
	solve(n); 
	
	int product = 1; 
	for (int i : distinct_p) {
		product *= i; 
	}
	cout << product << endl;
	return 0; 
}
