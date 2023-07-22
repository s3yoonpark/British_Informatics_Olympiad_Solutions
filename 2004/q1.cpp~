#include <bits/stdc++.h> 

using namespace std; 

// kin - 1 day 
// uinal - 20 days 
// tun - 18 uinals - 360 days 
// katun - 7200 days 
// baktun - 144000 days 

int main() {
	vector<int> m = {144000, 7200, 360, 20, 1}; 
	int x; 
	int s = 0; 
	for (int i = 0; i < 5; ++i) {
		cin >> x; 
		x *= m[i]; 
		s += x; 
	}
	
	// 2018843 = 1 January 2020
	int days = s - 2018843 + 1; 
	int f = 1441; 
	int year = 0; 
	int month = 0; 
	int day = 0; 
	
	int t = 2000; 
	while (1) {
		if (t % 4 == 0) {
			if (days > 366) {
				days -= 366; 
				++year; 
			} else {
				break; 
			}
		} else {
			if (days > 365) {
				days -= 365; 
				++year;
			} else {
				break; 
			}
		}
		++t; 
	}


	vector<int> d = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
	if (year % 4 == 0) d[1] = 29;

	for (int i = 0; i < d.size(); ++i) {
		if (days > d[i]) {
			days -= d[i]; 
		} else {
			month = i+1; 
			day = days; 
			break; 
		}
	}

	cout << day << " " << month << " " << year + 2000 << endl; 

	return 0; 
}
