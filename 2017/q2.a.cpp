#include <bits/stdc++.h>
using namespace std;

int a, p; 
int b, q;
int t; 

char sq[5][5]; 
bool path[37][37]; 
int clockwise[4] = {-6, 1, 6, -1}; 
int anticlockwise[4] = {-6, -1, 6, 1}; 

bool check(int n) {
	return n >= 1 && n <= 36; 
}

bool eval(int player) {
	char symbol; 
	if (player == 1) symbol = 'X';
	else symbol = 'O'; 
	bool changed = 0; 
	for (int i = 1; i <= 36; ++i) {
		if (sq[(i-i%5)/5][i%5-1] != '*') continue; 
		int c = i; 
		int d = i+1; 
		int e = i+7; 
		int f = i+6; 
		if (check(c) && check(d) && check(e) && check(f)) {
			if (path[c][d] && path[d][e] && path[e][f] && path[f][c]) {
				sq[(i-i%5)/5][i%5-1] = symbol; 
				changed = 1; 
			}
		}		
	}
	return changed; 
}

void amove() {
	cout << 1 << '\n'; 
	a += p; 
	a %= 36; 
	if (!a) a += 36; 
	bool joined = 0; 
	while (!joined) {
		for (int j = 0; j < 4; ++j) {
			if (check(a+clockwise[j])) {
				if (path[a][a+clockwise[j]] || path[a+clockwise[j]][a]) {
					continue; 	
				} else {
					path[a][a+clockwise[j]] = 1;
					path[a+clockwise[j]][a] = 1; 
					joined = 1; 
					break; 
				}
			}
		}
		if (!joined) {
			++a; 
			a %= 36; 
			if (!a) a += 36; 
		}	
	}
	if (eval(1)) amove(); 
	return; 
}

void bmove() {
	cout << 2 << '\n'; 
	b += q; 
	b %= 36; 
	if (!b) b += 36; 
	// clockwise 
	bool joined = 0; 
	while (!joined) {
		for (int j = 0; j < 4; ++j) {
			if (check(b+anticlockwise[j])) {
				if (path[b][b+anticlockwise[j]] || path[b+anticlockwise[j]][a]) {
					continue; 	
				} else {
					path[b][b+anticlockwise[j]] = 1;
					path[b+anticlockwise[j]][b] = 1; 
					joined = 1; 
					break; 
				}
			}
		}
		if (!joined) {
			++b; 	
			b %= 36; 
			if (!b) b += 36; 
		}
	}
	if (eval(2)) bmove(); 
	return; 
}

void solve() {
	for (int i = 0; i < t; ++i) {
		amove(); 	
		bmove(); 
	}	
	cout << "HERE" << '\n'; 
	for (int i = 1; i <= 36; ++i) {
		for (int j = 1; j <= 36; ++j) {
			cout << i << ' ' << j << ' ' << path[i][j] << '\n'; 
		}
	}
	cout << "HERE" << '\n'; 
	int ac = 0, bc = 0; 
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << sq[i][j] << ' ';
			if (sq[i][j] == 'X') {
				++ac; 
			}
			if (sq[i][j] == 'O') {
				++bc; 
			}
		}
		cout << '\n'; 
	}
	cout << ac << ' ' << bc << '\n'; 
	return; 
}

int main() {
	//ios_base::sync_with_stdio(0); 
	//cin.tie(0); 
	memset(path, 0, sizeof(path)); 
	memset(sq, '*', sizeof(sq)); 
	cin >> a >> p >> b >> q >> t;
	solve(); 

	return 0; 
}
