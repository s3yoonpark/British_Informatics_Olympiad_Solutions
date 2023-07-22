#include <bits/stdc++.h> 
using namespace std; 

vector<char> dial1, dial2; 
int n; string p;  

int main() {
	n = 1e9; 
	for (int i = 'A'; i < 'A'+26; ++i) {
		dial1.push_back((char)i); 
	}	
	vector<char> temp (dial1.begin(), dial1.end()); 
	int ind = 0; 
	while (temp.size()) {
		ind += n-1; 
		ind %= temp.size(); 
		char selected = temp[ind]; 
		temp.erase(find(temp.begin(), temp.end(), selected)); 
		dial2.push_back(selected); 
	}
	for (int i = 0; i < 6; ++i) cout << dial2[i]; 
	cout << '\n'; 
	return 0; 
}
