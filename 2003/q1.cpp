#include <bits/stdc++.h> 

using namespace std; 

int main() {
	string s; 
	cin >> s; 
	
	int sum = 0; 
	int pos = 1; 
	for (int i = 0; i < s.length(); ++i) {
		if (isdigit(s[i])) {
			sum += (11 - i - 1) * (s[i] - '0'); 	
		} else {
			if (s[i] == 'X') {
				sum += 10; 
			} else {
				pos = i+1; 
			}
		}
	}

	int t = 11 - sum % 11; 

	cout << t / (11 - pos)<< endl; 


	return 0; 
}
