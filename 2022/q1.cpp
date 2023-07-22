#include <bits/stdc++.h> 

using namespace std; 

#define ll long long

string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

string solve(string& s) {
	int base = 'A'-1; 
	string ans; ans += s[0];  
	for (int i = 0; i < s.length()-1; ++i) {
		int n = (ans[i]-base) + (s[i+1]-base); 
		n %= 26; 
		if (!n) n = 26; 
		ans += (char)('A'-1+n); 
	}
	return ans; 
}

string decrypt(string& s) {
	int base = 'A'-1; 
	string ans = ""; ans += s[0]; 
	for (int i = 0; i < s.length()-1; ++i) {
		int n = (s[i+1]-base) - (s[i]-base); 
		if (n < 0) n += 26; 
		if (n == 0) n = 26; 
		ans += (char)(base+n); 
	}
	return ans;
}

string b() {
	return "ZZZZZ"; 
}

int c() {
	string a = "OLYMPIAD"; 
	int cnt = 0; 
	while (1) {
		a = solve(a); 	
		++cnt; 
		if (a == "OLYMPIAD") return cnt; 
	}
}

void process(int& cnt, string tmp) {
	if (tmp.length() == 3) {
		ll cycle = 0; 
		string t = tmp; 
		while (1) {
			t = solve(t); 
			++cycle; 
			if (t == tmp) break; 
		}
		if (999999999999 % cycle == 0) ++cnt; 
		return; 
	}
	for (char& i : ALPHABET) {
		process(cnt, tmp+i); 
	}
	return; 
}

int d() {
	int cnt = 0;
	process(cnt, ""); 
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	string s; 
	cin >> s; 

	cout << "1(a): " << decrypt(s) << "\n";
	cout << "1(b): " << b() << "\n"; 
	cout << "1(c): " << c() << "\n"; 
	cout << "1(d): " << d() << "\n"; 


	return 0; 
}
