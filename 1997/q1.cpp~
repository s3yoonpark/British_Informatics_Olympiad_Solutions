#include <bits/stdc++.h> 

using namespace std; 

vector<string> tens = {"", "", "twenty", "thirty", "fourty", "fifty"}; 
vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}; 

string pretty_print(int h, int m) {
	string ans = ""; 
	if (m == 0) {
		ans += ones[h]; 	
		ans += " "; 
		ans += "o'clock";
		ans[0] = toupper(ans[0]); 
		return ans; 
	}

	if (m < 15) {
		ans += ones[m]; 
		ans += " minutes past "; 
		ans += ones[h];  
		ans[0] = toupper(ans[0]); 
		return ans; 
	}

	if (m == 15) {
		ans = "Quarter past " + ones[h]; 
		return ans; 
	}

	if (m > 15 && m < 30) {
		if (m < 20) {
			ans += ones[m]; 
			ans += " minutes past "; 
			ans += ones[h]; 
			ans[0] = toupper(ans[0]); 
			return ans;
		}
		string tm; 
		int tt = to_string(m)[0] - '0'; 
		int to = to_string(m)[1] - '0'; 
		tm = tens[tt] + " " + ones[to]; 	
		ans += tm; 
		ans += " minutes past "; 
		ans += ones[h]; 
		ans[0] = toupper(ans[0]); 
		return ans; 
	}

	if (m == 30) {
		ans = "Half past " + ones[h]; 
		return ans; 
	}

	if (m > 30 && m < 45) {
		string tm; 
		int tt = to_string(m)[0] - '0'; 
		int to = to_string(m)[1] - '0'; 
		tm = tens[tt] + " " + ones[to]; 	
		ans += tm; 
		ans += " minutes past "; 
		ans += ones[h]; 
		ans[0] = toupper(ans[0]); 
		return ans; 

	}

	if (m == 45) {
		ans = "Quarter to " + ones[h+1]; 
		return ans; 
	}

	if (m > 45 && m < 60) {
		int tm = 60 - m; 
		ans += ones[tm]; 
		ans += " minutes to "; 
		ans += ones[h+1]; 
		ans[0] = toupper(ans[0]); 
		return ans; 
	}
	return "N/A"; 
}

int main() {
	int h, m; 
	cin >> h >> m; 
	cout << pretty_print(h, m) << "\n"; 


	return 0; 
}
