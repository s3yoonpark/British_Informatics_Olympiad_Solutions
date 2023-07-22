#include <bits/stdc++.h> 

using namespace std; 

unordered_map<int,int> mp; 

int fib(int n) {
    if (mp.find(n) != mp.end()) return mp[n]; 
    if (n <= 1) return mp[n] = n; 
    return mp[n] = fib(n-1) + fib(n-2); 
}

void solve(vector<int>& fibonacci, vector<int>& ans, int n) {
    if (n == 0) return; 
    for (int i = fibonacci.size()-1; i >= 0; --i) {
        if (fibonacci[i] > n) {
            fibonacci.pop_back(); 
            continue; 
        }
        ans.push_back(fibonacci[i]); 
        return solve(fibonacci, ans, n - fibonacci[i]); 
    }
    return; 
}

int main() {
    vector<int> fibonacci; 
    int n; 
    cin >> n; 
    vector<int> ans; 

    int counter = 2; 
    while (true) {
        if (fib(counter) <= n) {
            fibonacci.push_back(fib(counter)); 
            ++counter; 
        } else {
            break; 
        }
    }

    solve(fibonacci, ans, n); 
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl; 

    return 0; 
}
