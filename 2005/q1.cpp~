#include <bits/stdc++.h> 

using namespace std; 

string solve(double n) {
	string t = to_string(n); 
	int a, b; 
	a = pow(10, (t.length() - 2)); 
	b = stoi(t.substr(2, t.length()-2));  
	int g = gcd(a, b); 
	string sa = to_string(a / g); 
	string sb = to_string(b / g); 
	return sb + "/" + sa; 
}

int main() {
	double n; 
	cin >> n; 
	cout << solve(n) << "\n"; 

	return 0; 
}
