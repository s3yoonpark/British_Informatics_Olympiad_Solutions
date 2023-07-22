#include <bits/stdc++.h>

using namespace std;

#define ll long long

unordered_map<int, ll> mp;

ll factorial(int n) {
    if (mp.find(n) != mp.end()) return mp[n];
    if (n <= 1) return n;
    return mp[n] = n * factorial(n - 1);
}

void solve() {
    string ALPHABET = "ABCD";
    vector<int> arr(4, 0);
    ll n;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> n;

    string res = "";
    int org = arr[0] + arr[1] + arr[2] + arr[3]; 

    while (res.length() != org) {
        bool ok = true;
        ll sum = arr[0] + arr[1] + arr[2] + arr[3];
        ll prod = factorial(sum);
        for (int i : arr) {
            if (i > 1) {
                prod /= factorial(i);
            }
        }
        ll temp = 0;
        for (int i = 0; i < arr.size() && ok; ++i) {
            // cout << endl; 
            // cout << res << endl;
            // cout << n << endl; 
            // cout << prod << " " << arr[i] << " " << sum << endl;
            // cout << prod * arr[i] / sum << endl;
            temp += prod * arr[i] / sum;
            if (temp >= n) {
                res += ALPHABET[i];
                n -= (temp - prod * arr[i] / sum);
                --arr[i];
                ok = false;
            }
        }
    }

    cout << res << endl;
}

int main() {
    // cout << factorial(25) << endl;
    solve();

    return 0;
}