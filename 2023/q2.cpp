#include <bits/stdc++.h>

using namespace std; 

vector<vector<char>> F = {{' ', '*', '*'}, 
                          {'*', '*', ' '},
                          {' ', '*', ' '}}; 

vector<vector<char>> G = {{'*', '*', ' '}, 
                          {' ', '*', '*'},
                          {' ', '*', ' '}}; 

vector<vector<char>> I = {{'*'},
                          {'*'},
                          {'*'},
                          {'*'},
                          {'*'}}; 

vector<vector<char>> L = {{'*'},
                          {'*'},
                          {'*'},
                          {'*', '*'}}; 

vector<vector<char>> J = {{' ', '*'},
                          {' ', '*'},
                          {' ', '*'},
                          {'*', '*'}}; 

vector<vector<char>> N = {{' ', '*'},
                          {'*', '*'},
                          {'*'},
                          {'*'}}; 

vector<vector<char>> M = {{'*', ' '},
                          {'*', '*'},
                          {' ', '*'},
                          {' ', '*'}}; 

vector<vector<char>> P = {{'*', '*'},
                          {'*', '*'},
                          {'*'}}; 

vector<vector<char>> Q = {{'*', '*'},
                          {'*', '*'},
                          {' ', '*'}}; 

vector<vector<char>> T = {{'*', '*', '*'},
                          {' ', '*'},
                          {' ', '*'}};    

vector<vector<char>> U = {{'*', ' ', '*'},
                          {'*', '*', '*'}};  

vector<vector<char>> V = {{'*'},
                          {'*'},
                          {'*', '*', '*'}};  

vector<vector<char>> W = {{'*'},
                          {'*', '*'},
                          {' ', '*', '*'}}; 

vector<vector<char>> X = {{' ', '*'},
                          {'*', '*', '*'},
                          {' ', '*'}};  

vector<vector<char>> Z = {{'*', '*'},
                          {' ', '*'},
                          {' ', '*', '*'}};  

vector<vector<char>> S = {{' ', '*', '*'},
                          {' ', '*'},
                          {'*', '*'}};  

vector<vector<char>> Y = {{' ', '*'},
                          {'*', '*'},
                          {' ', '*'},
                          {' ', '*'}}; 

vector<vector<char>> A = {{'*', ' '},
                          {'*', '*'},
                          {'*', ' '},
                          {'*', ' '}};   

vector<vector<vector<char>>> shapes = {F, G, I, L, J, N, M, P, Q, T, U, V, W, X, Z, S, Y, A}; 

bool check(vector<vector<char>>& temp) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (temp[i][j] == '-' && temp[i][j+1] == '*') return true; 
            if (temp[i][j] == '*' && temp[i][j+1] == '-') return true; 
        }
    }
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (temp[i][j] == '-' && temp[i+1][j] == '*') return true; 
            if (temp[i][j] == '*' && temp[i+1][j] == '-') return true; 
        }
    }
    return false; 
}

int solve(vector<vector<char>>& a, vector<vector<char>>& b) {
    int ans = 0; 

    vector<vector<char>> empty (20, vector<char>(20, ' ')); 

    // paste the shape b onto an empty board with centre 10, 10
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[i].size(); ++j) {
            if (b[i][j] == '*') {
                empty[i + 10][j + 10] = '*'; 
            }
        }
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            vector<vector<char>> temp (empty.begin(), empty.end()); 
            // new centre 
            bool ok = true; 
            for (int k = 0; k < a.size() && ok; ++k) {
                for (int l = 0; l < a[k].size() && ok; ++l) {
                    if (a[k][l] == '*') {
                        if (k + i < 20 && l + j < 20) {
                            if (temp[k+i][l+j] != '*') {
                                temp[k+i][l+j] = '-';
                            } else {
                                ok = false; 
                            }
                        } else {
                            ok = false; 
                        }
                    }
                }
            }
            if (!ok) continue; 
            
            if (check(temp)) {
                ans += 1; 
                for (int i = 0; i < 20; ++i) {
                    for (int j = 0; j < 20; ++j) {
                        cout << temp[i][j]; 
                    }
                    cout << endl; 
                }
                cout << "----------------------------------" << endl; 
            }
        } 
    }

    return (a == b) ? ans/2 : ans; 
}





int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    string lst = "FGILJNMPQTUVWXZSY"; 
    string input; 
    cin >> input; 
    vector<vector<char>> a = shapes[find(lst.begin(), lst.end(), input[0]) - lst.begin()]; 
    vector<vector<char>> b = shapes[find(lst.begin(), lst.end(), input[1]) - lst.begin()]; 

    cout << solve(a, b); 
 
    return 0;   
}
