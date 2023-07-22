#include <bits/stdc++.h> 

using namespace std; 

vector<int> gen_prime(int n) {
	vector<int> res; 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 

	for (int p = 2; p * p <= n; ++p) {
		if (prime[p]) {
			for (int i = p*p; i <= n; i += p) {
				prime[i] = false; 
			}
		}
	}

	for (int p = 2; p <= n; ++p ){
		if (prime[p]) {
			res.push_back(p); 
		}
	}
	return res; 
}

bool solve(int a, int b, vector<int>& res) {
	if (a == b) return false; 
	int o1 = a; 
	int o2 = b; 
	vector<int> pa, pb; 
	while (a != 1) {
		for (int i : res) {
			if (a % i == 0) {
				a /= i;
				pa.push_back(i); 
				break; 
			}
		}
	}
	while (b != 1) {
		for (int i : res) {
			if (b % i == 0) {
				b /= i; 
				pb.push_back(i); 
				break; 
			}
		}
	}
	
	int sa, sb; 
	sa = 1; sb = 1; 
	
	for (int i = 0; i < pa.size(); i = i) {
		int c = count(pa.begin(), pa.end(), pa[i]); 
		int temp = 0; 
		for (int j = 0; j <= c; ++j) {
			temp += pow(pa[i], j); 
		}
		sa *= temp; 
		i += c; 
	}
	sa -= o1; 

	for (int i = 0; i < pb.size(); i = i) {
		int c = count(pb.begin(), pb.end(), pb[i]); 
		int temp = 0; 
		for (int j = 0; j <= c; ++j) {
			temp += pow(pb[i], j); 
		}
		sb *= temp; 
		i += c; 
	}
	sb -= o2; 
	cout << sa << " " << sb << "\n"; 
	
	return (sa == o2) && (sb == o1); 	
}

int main() {
	vector<int> res = gen_prime(10000); 
	//for (int i = 0; i < 100; ++i) {
		//cout << res[i] << " "; 
	//}
	//cout << "\n";
	int a, b; 
	cin >> a >> b; 
	cout << (solve(a, b, res) ? "Amicable" : "Not amicable") << "\n"; 

	return 0; 
}
