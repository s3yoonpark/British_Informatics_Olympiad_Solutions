#include <bits/stdc++.h> 
using namespace std; 

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; 
int input[3][2]; 
unordered_map<string, int> dist; 
int s, f; 
string Ss, Sf; 

string convert(int n) {
	string res = "";
	for (char c : to_string(n)) {
		int digit = c - '0'; 
		res += digits[digit]; 
	}
	return res; 
}

bool possible(string& a, string& b) {
	int diff1[26]; 
	int diff2[26];
	memset(diff1, 0, sizeof(diff1)); 
	memset(diff2, 0, sizeof(diff2)); 
	for (char c : a) {
		++diff1[c-'A']; 
	}
	for (char c : b) {
		++diff2[c-'A']; 	
	}
	int sum = 0; 
	for (int i = 0; i < 26; ++i) {
		sum += abs(diff1[i] - diff2[i]); 
	}
	return sum <= 5; 
}

void solve(int n) {
	dist.clear(); 
	s = input[n][0]; 
	f = input[n][1]; 
	Ss = convert(s); 	
	Sf = convert(f); 
	queue<string> qu; 	
	qu.push(Ss); 
	dist[Ss] = 0; 
	while (!qu.empty()) {
		string S_now = qu.front(); qu.pop(); 
		int dist_now = dist[S_now]; 
		if (S_now == Sf) {
			cout << dist_now << '\n'; 
			break; 
		}
		for (int i = 1; i <= 999; ++i) {
			string t = convert(i); 
			if (dist[t]) continue; 
			if (possible(t, S_now)) {
				qu.push(t); 
				dist[t] = dist_now + 1; 
			}
		}
	}

	return; 
}

int main() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> input[i][j]; 
		}
	}	
	for (int i = 0; i < 3; ++i) {
		solve(i); 
	}

	return 0; 
}
