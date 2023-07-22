#include <bits/stdc++.h> 

using namespace std; 

#define ll long long 

unordered_map<string, ll> mp; 

ll Count(vector<int>& lst, string state, int sum) {
	if (mp.find(state) != mp.end()) return mp[state];  

	ll total = 0; 

	if (state.length() == sum) return 1; 

	for (int i = 0; i < lst.size(); ++i) {
		char c = (char)(i + 65); 
		if (lst[i] == 0) continue; 	
		if (lst[i] <= count(state.begin(), state.end(), c)) {
			continue; 
		} else {
			total += Count(lst, state + c, sum); 
		}
	}

	return mp[state] = total; 
}

string solve(vector<int>& lst, ll n) {
	vector<char> available = {'A', 'B', 'C', 'D'}; 
	
	int sum = 0; 
	for (int i : lst) sum += i; 

	string ans = ""; 

	while (ans.length() != sum) {
		for (char i : available) {
			if (count(ans.begin(), ans.end(), i) + 1 > lst[i - 65]) continue; 
			ll ways = Count(lst, ans+i, sum); 
			if (ways < n) {
				n -= ways; 
			} else {
				ans += i; 
				break; 
			}
		}
	}

	return ans; 
}

int b() {
	mp.clear();
	vector<int> lst_b = {2, 2, 2, 2}; 
	int counter = Count(lst_b, "", 8); 
	for (int i = 1; i <= counter; ++i) {
		if (solve(lst_b, i) == "AABCCBDD") {
			return i; 
		}
	}
}

int main() {
	vector<int> lst (4, 0); 
	ll n; 
	for (int i = 0; i < lst.size(); ++i) {
		cin >> lst[i]; 
	}
	cin >> n; 

	cout << solve(lst, n) << "\n"; 

	cout << b() << "\n";  

	return 0; 
}
