#include <bits/stdc++.h> 
using namespace std; 

vector<char> dial1, dial2; 
int n; string p;  

int main() {
	cin >> n >> p; 
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
	int baseline = 0; 	
	string ans = ""; 
	for (char c : p) {
		int tmp = c - 'A'; 
		ans += dial2[(tmp+baseline)%26]; 
		++baseline; 
	}
	cout << ans << '\n'; 

	return 0; 
}
