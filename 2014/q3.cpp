#include <iostream> 
using namespace std;

typedef unsigned long long ull; 

string NAME = "Seyoon Park", SCHOOL = "Harrow School"; 

const int mxL = 36; 
const string LIST = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
ull dp[mxL+1][mxL+1]; 
ull n; 

void init() {
	for (int j = 1; j <= mxL; ++j) dp[1][j] = 1; 

	for (int i = 2; i <= mxL; ++i) {
		for (int j = 1; j <= mxL; ++j) {
			for (int k = j+1; k <= mxL; ++k) {
				dp[i][j] += dp[i-1][k]; 
			}
		}
	}
}

string solve() {
	string ans = ""; 
	bool added = 0; 
	for (int i = 1; i <= mxL && !added; ++i) {
		for (int j = 1; j <= mxL && !added; ++j) {
			// length i starting with j 
			if (n > dp[i][j]) {
				n -= dp[i][j]; 
			} else {
				// found the correct one 
				added = 1; 
				int c = j; 
				ans += LIST[c-1]; 
				while ((int)ans.length() != i) {
					for (int k = c+1; k <= mxL; ++k) {
						if (n > dp[i-(int)ans.length()][k]) {
							n -= dp[i-(int)ans.length()][k]; 
						} else {
							c = k; 
							ans += LIST[k-1]; 
							break; 
						}
					}
				}
			}
		}
	}
	return ans; 
}
 
int main() {
	cout << "NAME : " << NAME << '\n'; 	
	cout << "SCHOOL : " << SCHOOL << '\n'; 

	init(); 
	cin >> n; 
	cout << solve() << '\n'; 

	return 0; 
}
