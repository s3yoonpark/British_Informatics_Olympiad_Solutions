#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
unordered_map<ll, ll> dist; 
ll d; 
string snum; 
ll maxdist; 
vector<ll> equivalent; 

void solve() {
	// bfs 
	queue<string> qu; 	
	qu.push(snum); 
	dist[stoll(snum)] = 0; 
	while (!(qu.empty())) {
		string a = qu.front();  
		ll curdist = dist[stoll(a)]; 
		equivalent.push_back(stoll(a)); 
		//cout << a << ' ' << curdist << '\n'; 
		maxdist = max(maxdist, curdist); 
		qu.pop(); 
		for (int i = 0; i < a.length()-1; ++i) {
			bool ok = 0; 
			int p=' ', q=' '; 
			// p is on the left of a[i]
			// q is on the right of a[i+1]
			if (i-1 >= 0) p=a[i-1]-'0';
			if (i+2<a.length()) q =a[i+2]-'0';
			if (p != ' ') {
				if ((p > (a[i]-'0') && p < (a[i+1]-'0')) || (p < (a[i]-'0') && p > (a[i+1]-'0'))) ok = 1;  
			}
			if (q != ' ') {
				if ((q > (a[i]-'0') && q < (a[i+1]-'0')) || (q < (a[i]-'0') && q > (a[i+1]-'0'))) ok = 1;  
			}
			if (ok) {
				string tmp (a.begin(), a.end()); 
				swap(tmp[i], tmp[i+1]); 
				if (!dist.count(stoll(tmp))) {
					dist[stoll(tmp)] = curdist+1; 
					qu.push(tmp); 
				}
			}
		}
	}
	cout << maxdist << '\n'; 
}

int main() {
	snum = "183654792"; 
	solve(); 
	vector<ll> tmp (equivalent.begin(), equivalent.end()); 	
	ll actualmaxdist=0; 
	for (ll i : tmp) {
		dist.clear(); 
		snum = to_string(i); 
		maxdist = 0; 
		solve(); 
		cout << i << ' ' << maxdist << '\n'; 
		actualmaxdist=max(actualmaxdist, maxdist); 
	}
	cout << actualmaxdist << '\n'; 

	return 0; 
}
