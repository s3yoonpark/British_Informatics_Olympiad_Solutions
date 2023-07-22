#include <bits/stdc++.h> 

using namespace std; 

bool check(string p) {
	for (int i = 0; i < p.length(); ++i) {
		for (int j = i-1; j >= 0; j -= 2) {
			int dist = i-j+1; 
			string a = p.substr(j, dist/2);  
			string b = p.substr(j+dist/2, dist/2); 
			if (a == b) {
				cout << a << " " << b << "\n";
				return false;
			}
		}
	}
	return true;
}

int main() {
	string p; 
	cin >> p; 
	cout << (check(p) ? "Accepted" : "Rejected") << "\n"; 


	return 0; 
}
