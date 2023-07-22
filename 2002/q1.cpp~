#include <bits/stdc++.h> 

using namespace std; 

int main() {
	unordered_map<string,int> mp; 
	mp["pa"] = 1; 
	mp["re"] = 2; 
	mp["ci"] = 3; 
	mp["vo"] = 4; 
	mp["mu"] = 5; 
	mp["xa"] = 6; 
	mp["ze"] = 7; 
	mp["bi"] = 8; 
	mp["so"] = 9; 
	mp["no"] = 0; 
	string n; 
	cin >> n; 
	string ans = ""; 
	for (int i = 0; i < n.length()-1; i+=2) {
		ans += to_string(mp[n.substr(i, 2)]); 
	}
	cout << ans << "\n";

	return 0; 
}
