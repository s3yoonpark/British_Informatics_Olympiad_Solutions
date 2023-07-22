#include <bits/stdc++.h> 
using namespace std; 

int l, p, q; 

const int mxN = (int)(pow(2,24)); 
int dist[mxN+1]; 
bool prime[mxN+1]; 

void gen() {
	memset(prime, 1, sizeof(prime)); 
	for (int i = 2; i*i <= mxN; ++i) {
		if (prime[i]) {
			for (int j = i*i; j <= mxN; j+=i) {
				prime[j] = 0; 
			}
		}
	}
	return; 
}

void solve() {
	queue<int> qu; 	
	qu.push(p); 
	dist[p] = 1; 
	while (!qu.empty()) {
		int num_now = qu.front(); qu.pop(); 
		int dist_now = dist[num_now]; 
		if (num_now == q) {
			cout << dist_now << '\n';
			break; 
		}
		// num_now - 2^i >= 2
		for (int i = 0; num_now - (int)pow(2,i) >= 2; ++i) {
			int t = num_now - (int)pow(2,i); 
			if (dist[t]) continue; 
			if (prime[t]) {
				qu.push(t); 
				dist[t] = dist_now+1; 
			}
		}
		for (int i = 0; num_now + (int)pow(2,i) <= l; ++i) {
			int t = num_now + (int)pow(2,i); 
			if (dist[t]) continue; 
			if (prime[t]) {
				qu.push(t); 
				dist[t] = dist_now+1; 
			}
		}
	}
	return; 
}

int main() {
	cin >> l >> p >> q; 		
	gen(); 
	solve(); 

	return 0; 
}
