#include <bits/stdc++.h>

using namespace std;

int lcm_finder(int a, int b) { return a * b / __gcd(a, b); }

void solve() {
    int a, b;
    cin >> a >> b;

    int counter = 1;
    while (1) {
        if ((60 + a) * counter % 1440 == (60 + b) * counter % 1440) {
            int total = (60 + a) * counter % 1440;
            int hour = total / 60;
            int minutes = total - hour * 60;
            string s_hour = to_string(hour);
            string s_minutes = to_string(minutes);
            if (s_hour.length() == 1) s_hour = "0" + s_hour;
            if (s_minutes.length() == 1) s_minutes = "0" + s_minutes;
            cout << s_hour << ":" << s_minutes << endl;
            break;
        }
        counter++;
    }
}
// 1 31
// 61x%1440 91x%1440

int main() {
    solve();

    return 0;
}