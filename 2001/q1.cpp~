#include <bits/stdc++.h> 

using namespace std; 

int main() {
	int n, l; 
	cin >> n >> l; 

	vector<int> lst (n, 0); 
	for (int i = 0; i < lst.size(); ++i) {
		lst[i] = i+1; 
	}
	int start = 0; 
	while (lst.size() != 1) {
		start = (start + l - 1) % (lst.size()); 
		lst.erase(start + lst.begin()); 
	}
	cout << "Number " << lst[0] << " is left" << "\n";



	return 0; 
}
