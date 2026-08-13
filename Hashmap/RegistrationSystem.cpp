#include <bits/stdc++.h>

using namespace std;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unordered_map<string, int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!mp.count(s)) {
            cout << "OK\n";
            mp[s] = 1;
        }
        else {
            cout << s + to_string(mp[s]) << "\n";
            mp[s]++;
        }
    }
    return 0;
}