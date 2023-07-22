/*
NAME: SEYOON PARK
SCHOOL: HARROW SCHOOL
*/ 

#include <bits/stdc++.h> 

using namespace std; 

string ALPHA = "ABCDEFGHIJKLMONOPQRSTUVWXYZ"; 
string plan; 
int p, q; 
int big;
char pos; 

struct room {
	char letter; 
	vector<char> exits; 
}; 
typedef struct room room; 

int record[10][10]; 
int vis[10]; 
room desc[10]; 

vector<string> ans = {"BCDEF", "A", "A", "A", "A", "A"}; 

bool solve(string plan) {
	big = plan.length()+2; 
	ALPHA = ALPHA.substr(0, big); 
	vector<char> tv (ALPHA.begin(), ALPHA.end()); 
	// form the plan 
	string curplan = plan; 
	for (char i : plan) {
		char first; 
		for (char j : tv) {
			if (curplan.find(j) == -1) {
				first = j; 
				break; 
			}
		}
		desc[first-'A'].letter = first; 
		desc[first-'A'].exits.push_back(i); 
		desc[i-'A'].letter = i; 
		desc[i-'A'].exits.push_back(first); 
		tv.erase(find(tv.begin(), tv.end(), first)); 
		curplan = curplan.substr(1, curplan.length()-1); 
	}
	desc[tv[1]-'A'].letter = tv[1]; 
	desc[tv[1]-'A'].exits.push_back(tv[0]); 	
	desc[tv[0]-'A'].letter = tv[0]; 
	desc[tv[0]-'A'].exits.push_back(tv[1]); 

	int cnt = 0; 
	for (int i = 0; i < big; ++i) {
		sort(desc[i].exits.begin(), desc[i].exits.end()); 
		string tmp (desc[i].exits.begin(), desc[i].exits.end()); 
		if (tmp != ans[cnt]) return false; 
		++cnt; 
	}
	return true; 
}

int main() {
	cout << "A" << '\n'; 
	for (int a = 0; a < 6; ++a) {
		for (int b = 0; b < 6; ++b) {
			for (int c = 0; c < 6; ++c) {
				for (int d = 0; d < 6; ++d) {
					char A = (char)(a+'A'); 
					char B = (char)(b+'A'); 
					char C = (char)(c+'A'); 
					char D = (char)(d+'A'); 
					string s = ""; 
					s += A; 
					s += B; 
					s += C; 
					s += D; 
					if (solve(s)) {
						cout << s << '\n'; 
					}
				}
			}
		}	
	}

	return 0; 
}
