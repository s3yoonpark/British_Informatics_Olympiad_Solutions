#include <bits/stdc++.h> 

using namespace std; 

int solve(string s) {
	vector<string> digits = {"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; 
	for (int i = 0; i < digits.size(); ++i) {
		int c = 0; 
		for (char j : s) {
			if (digits[i][c] == j) {
				++c; 
			}
			if (c == digits[i].length()) {
				return i+1; 
			}
		}
	}
	return 0; 
}

int main() {
	string s; 
	cin >> s; 
	int ans = solve(s); 	
	if (ans == 0) {
		cout << "NO" << "\n"; 
	} else {
		cout << ans << "\n"; 
	}

	return 0; 
}
