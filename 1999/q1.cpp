#include <bits/stdc++.h> 

using namespace std; 

unordered_set<int> river_1, river_3, river_9; 

pair<int,int> solve(int n) {
	pair<int,int> ans; 
	while (1) {
		if (river_1.count(n)) {
			ans.first = 1; 
			ans.second = n; 
			return ans; 
		}
		if (river_3.count(n)) {
			ans.first = 3; 
			ans.second = n; 
			return ans; 
		}
		if (river_9.count(n)) {
			ans.first = 9; 
			ans.second = n; 
			return ans;
		}

		int ts = 0; 
		for (char i : to_string(n)) {
			ts += i - '0'; 
		}
		n += ts; 
	}

	return ans;
}

int main() {
	int cur = 1; 
	while (cur <= 30000) {
		river_1.insert(cur); 
		int ts = 0; 
		for (char i : to_string(cur)) {
			ts += i - '0'; 
		}
		cur += ts; 
	}

	cur = 3; 
	while (cur <= 30000) {
		river_3.insert(cur); 
		int ts = 0; 
		for (char i : to_string(cur)) {
			ts += i - '0'; 
		}
		cur += ts; 
	}

	cur = 9; 
	while (cur <= 30000) {
		river_9.insert(cur); 
		int ts = 0; 
		for (char i : to_string(cur)) {
			ts += i - '0'; 
		}
		cur += ts; 
	}
	int n; 
	cin >> n; 
	pair<int,int> ans = solve(n); 
	cout << "First meets river " << ans.first << " at " << ans.second << "\n";  


	return 0; 
}
