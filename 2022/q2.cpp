// try a different approach to sorting 
// instead of relying on custom sort functions 
// use normal sorting 
#include <bits/stdc++.h> 

using namespace std; 

char hexagon[26][7]; 

int r, b, s, f; 

int rh = 1, re = 1, bh = 25, be = 6; 

void evaluate(int& red, int& blue) {
	for (int h = 1; h <= 25; ++h) {
		int rcnt = 0, bcnt = 0; 
		for (int e = 1; e <= 6; ++e) {
			if (hexagon[h][e] == 'r') ++rcnt; 
			if (hexagon[h][e] == 'b') ++bcnt; 
		}
		if (rcnt > bcnt) ++red; 
		if (bcnt > rcnt) ++blue; 
	}
	return; 
}

void update(int h, int e, char c) {
	hexagon[h][e] = c; 
	if (e == 1 && h >= 6 && h != 10 && h != 20) {
		if (6 <= h && h <= 9) {
			hexagon[h-4][4] = c; 
		}
		if (11 <= h && h <= 15) {
			hexagon[h-5][4] = c; 
		}
		if (16 <= h && h <= 19) {
			hexagon[h-4][4] = c; 
		}
		if (21 <= h && h <= 25) {
			hexagon[h-5][4] = c; 
		}
	}

	if (e == 2 && h%5 != 0) {
		hexagon[h+1][5] = c; 
	}

	if (e == 3 && h <= 20 && h!= 10 && h != 20) {
		if (1 <= h && h <= 5) {
			hexagon[h+5][6] = c; 
		} 
		if (6 <= h && h <= 9) {
			hexagon[h+6][6] = c; 
		}
		if (11 <= h && h <= 15) {
			hexagon[h+5][6] = c; 
		}
		if (16 <= h && h <= 19) {
			hexagon[h+6][6] = c; 
		}
	}

	if (e == 4 && h <= 20 && h != 11 && h != 1) {
		if (2 <= h && h <= 5) {
			hexagon[h+4][1] = c; 
		}
		if (6 <= h && h <= 10) {
			hexagon[h+5][1] = c; 
		}
		if (12 <= h && h <= 15) {
			hexagon[h+4][1] = c; 
		}
		if (16 <= h && h <= 20) {
			hexagon[h+5][1] = c; 
		}
	}

	if (e == 5 && h%5 != 1) {
		hexagon[h-1][2] = c; 
	}

	if (e == 6 && h >= 6 && h != 11 && h != 21) {
		if (6 <= h && h <= 10) {
			hexagon[h-5][3] = c; 
		}
		if (12 <= h && h <= 15) {
			hexagon[h-6][3] = c; 	
		}
		if (16 <= h && h <= 20) {
			hexagon[h-5][3] = c; 
		}
		if (22 <= h && h <= 25) {
			hexagon[h-6][3] = c; 
		}
	}
	return; 
}

void skirmishes() {
	update(rh, re, 'r'); 
	update(bh, be, 'b'); 
	++re; 	
	re %= 6; 
	if (!re) re = 6;
	rh += r; 
	rh %= 25; 
	if (!rh) rh = 25; 
	--be; 
	be %= 6;
	if (!be) be = 6; 
	bh += b; 
	bh %= 25; 
	if (!bh) bh = 25;

	return; 
}


void feuds() {
	// red 
	int red=0, blue=0; 		
	evaluate(red, blue); 
	vector<vector<int>> unowned; 
	for (int h = 1; h <= 25; ++h) {
		for (int e = 1; e <= 6; ++e) {
			if (hexagon[h][e] != ' ') continue; 
			update(h, e, 'r'); 
			int tred=0, tblue=0; 
			evaluate(tred, tblue); 
			unowned.push_back({tred-red, blue-tblue, -h, -e}); 
			update(h, e, ' '); 
		}
	}
	sort(unowned.rbegin(), unowned.rend()); 
	update(-unowned[0][2], -unowned[0][3], 'r'); 

	// blue 
	red=0; blue=0;
	evaluate(red, blue); 
	unowned.clear(); 
	for (int h = 1; h <= 25; ++h) {
		for (int e = 1; e <= 6; ++e) {
			if (hexagon[h][e] != ' ') continue; 
			update(h, e, 'b'); 
			int tred=0, tblue=0; 
			evaluate(tred, tblue); 
			unowned.push_back({tblue-blue, red-tred, h, e}); 
			update(h, e, ' '); 
		}
	}
	sort(unowned.rbegin(), unowned.rend()); 
	update(unowned[0][2], unowned[0][3], 'b'); 

	return; 
}

void solve() {
	for (int i = 0; i < s; ++i) {
		skirmishes(); 
	}
	//cout << "H" << "\n"; 
	//for (int h = 1; h <= 25; ++h) {
		//for (int e = 1; e <= 6; ++e) {
			//cout << h << " " << e << " " << hexagon[h][e] << "\n"; 
		//}
	//}
	//cout << "H" << "\n"; 
	for (int i = 0; i < f; ++i) {
		feuds(); 
	}
	int red=0, blue=0; 
	evaluate(red, blue); 
	cout << red << "\n"; 
	cout << blue << "\n"; 

	return;
}

int main() {
	memset(hexagon, ' ', sizeof(hexagon)); 
	cin >> r >> b >> s >> f; 
	solve(); 	

	return 0; 
}
