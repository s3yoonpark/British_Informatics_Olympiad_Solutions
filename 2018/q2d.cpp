#include <bits/stdc++.h> 
using namespace std; 

int n; string p;  
string ORIGINAL = "ABCD"; 

int main() {
	p = "ABCD"; 
	for (n = 1; n <= 1000000; ++n) {
		vector<char> dial1, dial2; 
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
		int baseline = 0; 	
		string ans = ""; 
		int num = 0; 
		while (1) {
			for (char c : p) {
				int tmp = c - 'A'; 
				ans += dial2[(tmp+baseline)%26]; 
			}
			if (ans != ORIGINAL) {
				p = ans; 
				ans = ""; 
			}	
			++num; 
		}
		p = ORIGINAL; 
		cout << num << '\n'; 
	}
	return 0; 
}
