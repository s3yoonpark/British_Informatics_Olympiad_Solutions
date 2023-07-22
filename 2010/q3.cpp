#include <bits/stdc++.h>

using namespace std; 

string convert(vector<int>& lst) {
    string res = ""; 
    for (int i = 0; i < lst.size()-1; ++i) {
        res += to_string(lst[i]) + " "; 
    }
    return res; 
}

void solve() {
    unordered_map<string, bool> mp; 
    int j, n;
    cin >> j >> n; 
    vector<int> lst (j, 0); 
    for (int i = 0; i < j; ++i) cin >> lst[i]; 

    vector<int> New (lst.size()+1, 0); 

    queue<vector<int>> q; 
    q.push(New); 

    mp[convert(New)] = true; 
    
    while(!q.empty()) {
        vector<int> t (q.front().begin(), q.front().end()); 
        q.pop(); 
        bool found = true; 
        for (int i = 0; i < t.size()-1 && found; ++i) {
            if (t[i] == n) {
                found = false; 
            }
        }
        if (!found) {
            cout << t[t.size()-1] << endl; 
            break; 
        }

        for (int i = 0; i < t.size()-1; ++i) {
            // i -> moving from 
            // j -> moving to
            vector<int> newEmpty (t.begin(), t.end()); 
            newEmpty[newEmpty.size()-1] += 1; 
            newEmpty[i] = 0; 
            if (mp.find(convert(newEmpty)) == mp.end()) {
                q.push(newEmpty); 
                mp[convert(newEmpty)] = true; 
            }

            vector<int> newFill(t.begin(), t.end()); 
            newFill[newFill.size()-1] += 1; 
            newFill[i] = lst[i]; 
            if (mp.find(convert(newFill)) == mp.end()) {
                q.push(newFill); 
                mp[convert(newFill)] = true; 
            }

            for (int j = 0; j < t.size()-1; ++j) {
                if (i == j) continue; 
                vector<int> newMove (t.begin(), t.end()); 
                newMove[newMove.size()-1] += 1; 
                int BRUH = newMove[i]; 
                newMove[i] -= min(BRUH, lst[j] - newMove[j]); 
                newMove[j] += min(BRUH, lst[j] - newMove[j]); 
                if (mp.find(convert(newMove)) == mp.end()) {
                    q.push(newMove); 
                    mp[convert(newMove)] = true; 
                }
            }
        }
    }
    return; 
}

int main() {
    solve(); 

    return 0; 
}