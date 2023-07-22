#include <bits/stdc++.h>

using namespace std; 

#define ll long long 

void solve() {
    bool ok = 0; 
    ll n; 
    cin >> n; 
    string temp = to_string(n); 
    sort(temp.begin(), temp.end()); 
    for (int i = 2; i <= 9; ++i) {
        string check = to_string(n * i);
        sort(check.begin(), check.end()); 
        if (check == temp) {
            ok = 1; 
            cout << i << " "; 
        }
    }
    if (!ok) cout << "NO"; 
    return; 
}

int main() {
    solve(); 

    return 0; 
}
