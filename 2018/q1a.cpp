#include <bits/stdc++.h> 
using namespace std; 

double debt = 10000; 
double ans = 0; 
double interest, repayment; 

int main() {
	cin >> interest >> repayment; 
	interest /= 100; 
	repayment /= 100; 

	while (debt) {
		debt += debt * interest;  
		debt = ceil(debt); 
		double pay; 
		if (5000 > debt * repayment) pay = 5000; 
		else pay = debt * repayment; 
		if (pay > debt) pay = debt; 
		pay = ceil(pay); 
		debt -= pay; 
		debt = ceil(debt); 
		ans += pay; 
	}
	cout << ans/100 << '\n'; 

	return 0; 
}
