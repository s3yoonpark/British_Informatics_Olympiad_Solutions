#include <bits/stdc++.h>

using namespace std; 

unordered_map<string, int> mp; 
unordered_map<string, bool> history; 

string convert(vector<string>& n) {
    string res = ""; 

    for (string i : n) {
        res += i; 
        res += ' '; 
    }

    return res; 
}

int solve(vector<string>& start, vector<string>& end) {
    queue<vector<string>> q; 
    q.push(start);  
    mp[convert(start)] = 0; 

    while (!q.empty()) {
        vector<string> f = q.front(); 
        q.pop(); 
        if (history.find(convert(f)) != history.end()) continue; 
        history[convert(f)] = true; 
        int cur = mp[convert(f)]; 
        if (f == end) return cur; 

        for (int i = 0; i < f.size(); ++i) {
            if (f[i] == "0") continue; // if it's empty what you gonna move? :skull:
            // where from 
            for (int j = 0; j < f.size(); ++j) {
                // where to
                if (i == j) continue; // you don't want to move it to the same peg
                if (f[j].length() == 4) continue; // you can't move it to one with maximum size
                vector<string> temp (f.begin(), f.end()); 
                if (temp[j] == "0") {
                    temp[j] = temp[i][temp[i].length() - 1]; 
                } else {
                    temp[j] += temp[i][temp[i].length() - 1]; 
                }
                if (temp[i].length() == 1) {
                    temp[i] = "0"; 
                } else {
                    temp[i] = temp[i].substr(0, temp[i].length() - 1); 
                }
                if (mp.find(convert(temp)) != mp.end()) continue; 
                q.push(temp); 
                mp[convert(temp)] = cur + 1; 
                // cout << convert(f) << " " << convert(temp) << " " << cur << endl; 
            }
        }
    }

    return 1; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    vector<string> start (4, ""); 
    vector<string> end (4, ""); 
    for (int i = 0; i < start.size(); ++i) {
        cin >> start[i]; 
    }

    for (int i = 0; i < end.size(); ++i) {
        cin >> end[i]; 
    }

    cout << solve(start, end); 


    return 0; 
}
