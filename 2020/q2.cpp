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

void solve() {
	memset(vis, 0, sizeof(vis)); 
	memset(record, 0, sizeof(record)); 
	cin >> plan; 
	big = plan.length()+2; 
	ALPHA = ALPHA.substr(0, big); 
	vector<char> tv (ALPHA.begin(), ALPHA.end()); 
	cin >> p >> q; 

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

	for (int i = 0; i < big; ++i) {
		sort(desc[i].exits.begin(), desc[i].exits.end()); 
		for (char j : desc[i].exits) {
			cout << j; 
		}
		cout << '\n'; 
	}

	if (p > q) swap(p, q); 
	pos = 'A'; 
	for (int i = 0; i < q; ++i) {
		++vis[pos-'A']; 
		if (vis[pos-'A'] % 2 == 1) {
			++record[pos-'A'][desc[pos-'A'].exits[0]-'A']; 
			pos = desc[pos-'A'].exits[0]; 
		} else {
			for (int j = 0; j < desc[pos-'A'].exits.size(); ++j) {
				if (record[pos-'A'][desc[pos-'A'].exits[j]-'A'] % 2 == 1) {
					if (j == desc[pos-'A'].exits.size()-1) {
						++record[pos-'A'][desc[pos-'A'].exits[j]-'A']; 
						pos = desc[pos-'A'].exits[j]; 
					} else {
						++record[pos-'A'][desc[pos-'A'].exits[j+1]-'A']; 
						pos = desc[pos-'A'].exits[j+1]; 
					}
					break; 
				}
			}
		}
		if (i == p-1) {
			cout << pos; 
		}
	}
	cout << pos << '\n'; 
	return; 
}

int main() {
	solve(); 	

	return 0; 
}
