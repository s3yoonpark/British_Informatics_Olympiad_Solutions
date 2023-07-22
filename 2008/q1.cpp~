#include <bits/stdc++.h> 

using namespace std; 

set<int> pr; 

void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    for (int p = 2; p <= n; p++)
        if (prime[p])
			pr.insert(p); 
}

int solve(int n) {
	if (n == 2) return 1; 
	int c = 0; 
	for (int i : pr) {
		if (i > n/2) {
			break; 
		}
		if (pr.count(n-i)) {
			++c; 
		}
	}

	return c; 
}

int main() {
	SieveOfEratosthenes(10000); 
	int n; 
	cin >> n; 
	cout << solve(n) << "\n"; 



	return 0; 
}
