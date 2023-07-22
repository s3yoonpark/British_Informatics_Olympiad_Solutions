#include <bits/stdc++.h> 

using namespace std; 

string roman_numeral(int n) {
	vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 
	vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; 
	vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 
	vector<string> thousands = {"", "M", "MM", "MMM"}; 
	return thousands[n/1000] + hundreds[(n%1000)/100] + tens[(n%100)/10] + ones[n%10]; 
}

int main() {
	int n; 
	cin >> n; 
	cout << roman_numeral(n) << "\n"; 

	return 0; 
}
