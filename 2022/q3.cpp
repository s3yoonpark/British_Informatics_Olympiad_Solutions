#include <bits/stdc++.h> 

using namespace std; 

#define ull unsigned long long 

map<char, vector<char>> mp; 

string n; 
ull k; 

void solve() {
	vector<char> lst; 
	for (int i = 0; i < n.length(); ++i) {
		lst.push_back((char)('a'+i)); 
	}

	for (char i : lst) {
		int ind = n.find(i); 
		for (int j = ind; j >= 0; --j) {
			if (n[j] <= n[ind]) {
				mp[i].push_back((char)('A'+j)); 
			} else {
				break; 
			}
		}
		sort(mp[i].begin(), mp[i].end()); 
	}	

	string ans = ""; 

	for (int i = 0; i < lst.size(); ++i) {
		ull temp = 1; 
		for (int j = i+1; j < lst.size(); ++j) {
			temp *= mp[lst[j]].size(); 
		}
		int cnt = 0; 
		while (temp < k) {
			k -= temp; 
			++cnt; 
		}
		ans += mp[lst[i]][cnt]; 
	}
	cout << ans << "\n"; 
	
	return; 
}

void a() {
	cin >> n >> k; 	
	solve(); 
	return; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	a(); 	


	return 0; 
}
