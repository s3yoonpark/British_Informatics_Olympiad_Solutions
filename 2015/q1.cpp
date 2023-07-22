#include <bits/stdc++.h> 

using namespace std; 

unordered_map<string,int> mp; 

int solve(string s) {
	if (mp.count(s)) return mp[s]; 
	int total = 1; 
	for (int i = 0; i < s.length(); ++i) {
		if (i >= (int)s.length()/2) {
			continue; 
		}
		string temp = s.substr(0, i+1); 
		if (s.substr(s.length()-(i+1), i+1) == temp) {
			total += solve(s.substr(i+1, s.length() - 2 * (i+1))); 
		}
	}	

	return mp[s] = total; 
}

int main() {
	string s; 
	cin >> s; 
	cout << solve(s)-1 << "\n";
	cout << "\n";

	return 0; 
}
