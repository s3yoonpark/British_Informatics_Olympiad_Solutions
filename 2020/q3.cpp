#include <bits/stdc++.h> 

using namespace std; 

typedef unsigned long long ull;
typedef long long ll; 

string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
int p, q, r;
ull n; 
ull check[26][13][13];

// p - first p letters of the alphabet
// q - adjacent limit 
// r - limit on plan size

ull plan(string tmp, int adj) {
	if (adj <= 0) return 0; 
	if (check[tmp[tmp.length()-1]-'A'][adj][r-tmp.length()]) return check[tmp[tmp.length()-1]-'A'][adj][r-tmp.length()];  
	if (tmp.length() == r) {
		return 1; 
	} 
	ull total = 0; 
	for (char c : ALPHA) {
		total += plan(tmp+c, (c == tmp[tmp.length()-1]) ? adj-1 : q); 
	}
	return check[tmp[tmp.length()-1]-'A'][adj][r-tmp.length()] = total; 
}

void solve() {
	cin >> p >> q >> r >> n; 
	ALPHA = ALPHA.substr(0, p); 
	string ans = ""; 
	int cur = q; 
	while (ans.length() != r) {
		for (char c : ALPHA) {
			ull num = plan(ans + c, ((c == ans[ans.length()-1]) ? cur-1 : q)); 
			//cout << ans+c << ' ' << ((c == ans[ans.length()-1]) ? cur-1 : q) << ' ' << num << '\n'; 
			if (n > num) {
				n -= num; 
			} else {
				if (ans[ans.length()-1] == c) --cur; 
				else cur = q; 
				ans += c; 
				break; 
			}
		}
	}
	cout << ans << '\n'; 
}

int main() {
	ios_base::sync_with_stdio(0); 	
	cin.tie(0); 
	memset(check, 0, sizeof(check)); 
	solve(); 	

	return 0; 
}
