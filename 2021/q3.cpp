#include <bits/stdc++.h>

using namespace std;

int solve(string &s)
{
    // bfs question
    unordered_map<string, int> mp;
    queue<string> q;
    q.push("A");
    mp["A"] = 1;

    while (!q.empty())
    {
        string temp = q.front();
        q.pop();
        int cur = mp[temp];

        if (temp == s)
            return cur;
        if (temp.length() < s.length())
        {
            string new_temp = temp + (char)(*max_element(temp.begin(), temp.end()) + 1);
            if (mp.find(new_temp) == mp.end())
            {
                q.push(new_temp);
                mp[new_temp] = cur + 1;

                if (new_temp == s)
                    return mp[new_temp];
            }
        }

        if (temp.length() >= 2)
        {
            string new_temp = "";
            new_temp += temp[1];
            new_temp += temp[0];
            new_temp += temp.substr(2, temp.length() - 2);

            if (mp.find(new_temp) == mp.end())
            {
                q.push(new_temp);
                mp[new_temp] = cur + 1;

                if (new_temp == s)
                    return mp[new_temp];
            }
        }

        if (temp.length() >= 2)
        {
            string new_temp = "";
            new_temp += temp.substr(1, temp.length() - 1);
            new_temp += temp[0];

            if (mp.find(new_temp) == mp.end())
            {
                q.push(new_temp);
                mp[new_temp] = cur + 1;

                if (new_temp == s)
                    return mp[new_temp];
            }
        }
    }

    return -1;
}

void b() {
    string s = "ABCDE"; 

    do {
        if (solve(s) == 6) cout << s << endl; 
    } while (next_permutation(s.begin(), s.end())); 
}

int main()
{  
    string s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}
