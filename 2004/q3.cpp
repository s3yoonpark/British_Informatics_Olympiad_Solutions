#include <iostream> 
using namespace std;

string msg; 
string morse[26];

void process(int index, string tmp, int& cnt, string& morsed) {
	if (index == (int)morsed.length()) {
		// finished processing 
		if ((int)tmp.length() == (int)msg.length()) {
			cout << tmp << '\n'; 
			++cnt; 
		}	
		return; 
	}
	for (int i = 1; i <= min(4, (int)morsed.length() - index); ++i) {
		int match = -1; 
		string t = morsed.substr(index, i); 
		for (int j = 0; j < 26 && match == -1; ++j) {
			if (t == morse[j]) {
				match = j; 
			}
		}
		if (match != -1) {
			process(index+i, tmp + (char)('a'+match), cnt, morsed); 
		}
	}
	return; 
}

int solve() {
	string morsed = ""; 
	for (char i : msg) {
		morsed += morse[i-'a'];	
	}
	int cnt = 0; 
	process(0, "", cnt, morsed); 
	return cnt; 
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	morse[0] = ".-"; 
	morse[1] = "-..."; 
	morse[2] = "-.-."; 
	morse[3] = "-.."; 
	morse[4] = "."; 
	morse[5] = "..-."; 
	morse[6] = "--."; 
	morse[7] = "...."; 
	morse[8] = ".."; 
	morse[9] = ".---"; 
	morse[10] = "-.-"; 
	morse[11] = ".-.."; 
	morse[12] = "--"; 
	morse[13] = "-."; 
	morse[14] = "---"; 
	morse[15] = ".--."; 
	morse[16] = "--.-"; 
	morse[17] = ".-."; 
	morse[18] = "..."; 
	morse[19] = "-"; 
	morse[20] = "..-"; 
	morse[21] = "...-"; 
	morse[22] = ".--"; 
	morse[23] = "-..-"; 
	morse[24] = "-.--"; 
	morse[25] = "--.."; 
	cin >> msg; 
	cout << solve() << '\n'; 

	return 0; 
}
