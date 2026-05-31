#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long temp = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > temp) return false;
            temp += asteroids[i];
        }
        return true;
    }
};

int main() {
    int mass, n;
    cin >> mass >> n;
    vector<int> asteroids(n);
    for (int i = 0; i < n; i++) cin >> asteroids[i];
    Solution obj;
    cout << ((obj.asteroidsDestroyed(mass, asteroids) == 1) ? "True" : "False") << endl;
    return 0;
}