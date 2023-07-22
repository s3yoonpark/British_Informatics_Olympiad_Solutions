#include <bits/stdc++.h>

using namespace std; 

vector<int> solve(vector<int>& arr, int n) {
    vector<int> ans(2, -1); 
    int start = 1; 
    ans[0] = start; 

    while (true) {
        int index = find(arr.begin(), arr.end(), start) - arr.begin(); 
        start = arr[index+1]; 
        if (start == n) {
            int counter = start; 
            while (true) {
                arr[counter-1] = 0; 
                counter += start; 
                if (counter > arr.size()) break; 
                // 1 2 3 4 5 6 7 8 
            }
            arr.erase(remove(arr.begin(), arr.end(), 0), arr.end()); 
            continue; 
        }
        if (start > n) {
            ans[1] = start; 
            return ans; 
        }
        ans[0] = start; 
        int counter = start; 
        while (true) {
            arr[counter-1] = 0; 
            counter += start; 
            if (counter > arr.size()) break; 
            // 1 2 3 4 5 6 7 8 
        }
        arr.erase(remove(arr.begin(), arr.end(), 0), arr.end()); 

        // for (int i : arr) cout << i << " "; 
        // cout << endl; 
    }
}

int main() {
    int n; 
    cin >> n; 
    vector<int> arr(10000, -1); 

    for (int i = 0; i < arr.size(); ++i) arr[i] = 2*i + 1; 

    vector<int> ans = solve(arr, n); 

    cout << ans[0] << " " << ans[1];

    return 0; 
}
