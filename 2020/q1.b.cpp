#include <bits/stdc++.h> 

using namespace std; 

string convert(int n) {
	string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 
	string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; 
	string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "DM"}; 
	string thousands[] = {"", "M", "MM", "MMM"}; 
	
	return (thousands[n/1000] + hundreds[(n%1000)/100] + tens[(n%100)/10] + ones[n%10]);  
}


string solve(string roman, int n) {
	if (n == 0) {
		return roman; 	
	}	
	int counter = 1; 
	
	string res = ""; 	
	for (int i = 0; i < roman.length() - 1; ++i) {
		if (roman[i] == roman[i+1]) {
			counter += 1; 
		}
		else {
			res += convert(counter) + roman[i];  
			counter = 1; 
		}	
	}
	res += convert(counter) + roman[roman.length()-1]; 	
	return solve(res, n-1); 
}

unordered_map<string,bool> mp; 

int main () {
	int ans = 0; 
	for (int i = 1; i <= 3999; ++i) {
		mp[convert(i)] = 1; 
	}
	for (int i = 1; i <= 3999; ++i) {
		string tmp = solve(convert(i), 1); 
		if (mp[tmp]) {
			++ans; 
			cout << tmp << '\n'; 
		}
	}
	cout << ans << '\n'; 
	return 0; 
}
