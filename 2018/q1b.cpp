#include <bits/stdc++.h> 
using namespace std; 

double debt = 10000; 
double ans = 0; 
double interest, repayment; 
int num = 0; 

int main() {
	interest = 43; repayment = 46; 
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
		++num; 
	}
	cout << num << '\n'; 

	return 0; 
}
