#include <bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        vector<pair<int, string>>& vec = mp[key];
        int low = 0, high = vec.size() - 1;
        string ans = "";
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first == timestamp) return vec[mid].second;
            else if (vec[mid].first < timestamp) {
                ans = vec[mid].second;
                low = mid + 1;
            }
            else high = mid - 1; 
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */