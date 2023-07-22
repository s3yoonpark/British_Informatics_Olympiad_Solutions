#include <bits/stdc++.h> 
using namespace std; 

double debt = 10000; 
double ans = 0; 
double interest, repayment; 

vector<vector<double>> res; 

int main() {
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			interest = i/100.0; 
			repayment = j/100.0; 
			debt = 10000; 
			ans = 0; 
			double lastdebt = debt; 
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
				if (debt >= lastdebt) {
					ans = -1; 
					break; 
				}
				lastdebt = debt; 
			}
			ans /= 100; 
			res.push_back({ans, i, j}); 
		}
	}
	sort(res.rbegin(), res.rend()); 
	cout << res[0][1] << ' ' << res[0][2] << '\n';  

	return 0; 
}
