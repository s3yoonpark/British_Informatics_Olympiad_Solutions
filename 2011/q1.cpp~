#include <bits/stdc++.h> 

using namespace std; 

string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

char solve(string s, int n) {
	if (n <= 2) {
		return s[n-1]; 
	}
	int p1 = A.find(s[0])+1; 
	int p2 = A.find(s[1])+1; 
	for (int i = 0; i < n-2; ++i) {
		int temp = p1; 	
		p1 = p2; 
		p2 = temp + p1; 
		if (p2 > 26) p2 -= 26;
	}
	return A[p2-1]; 
}

int main() {
	string s = "AB"; 
	int n; 
	cin >> s[0] >> s[1] >> n; 
	cout << solve(s, n) << "\n"; 

	return 0; 
}
