#include <bits/stdc++.h> 

using namespace std; 

bool is_pat(string& s) {
	if (s.length() == 1) return true;

	for (int i = 0; i < s.length() - 1; ++i) {
		string l = s.substr(0, i+1); 
		string r = s.substr(i+1, s.length() - i - 1); 
		if (*min_element(l.begin(), l.end()) > *max_element(r.begin(), r.end())) {
			string temp_l = l; string temp_r = r; 
			reverse(temp_l.begin(), temp_l.end()); reverse(temp_r.begin(), temp_r.end()); 
			if (is_pat(temp_l) && is_pat(temp_r)) return true; 
		}
	}
	return false; 
}

void b() {
	string s = "ABCD"; 
	do {
		if (is_pat(s)) cout << s << endl; 
	} while (next_permutation(s.begin(), s.end())); 
}

void c() {
	string alphabet = "ACDEFGHIJKLMNOPQRSTUVWXYZ"; 
	int counter = 0; 
	do {
		string temp = 'B' + alphabet; 
		if (is_pat(temp)) counter += 1; 
	} while (next_permutation(alphabet.begin(), alphabet.end()));
	cout << counter;  
}


int main () {
	string s1, s2; 
	cin >> s1 >> s2; 
	string comb = s1 + s2; 
	cout << (is_pat(s1) ? "YES" : "NO") << endl; 
	cout << (is_pat(s2) ? "YES" : "NO") << endl; 
	cout << (is_pat(comb) ? "YES" : "NO") << endl; 
	return 0; 
}
