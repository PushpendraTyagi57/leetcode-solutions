#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    int snapId = 0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        auto& vec = mp[index];
        if (!vec.empty() && vec.back().first == snapId) {
            vec.back().second = val;
        }
        else {
            mp[index].push_back({snapId, val});
        }
    }
    
    int snap() {
        snapId++;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        auto& vec = mp[index];
        int low = 0, high = vec.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first <= snap_id) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans == -1 ? 0 : vec[ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */