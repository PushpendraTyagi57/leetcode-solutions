#include <bits/stdc++.h>

using namespace std;

class LFUCache {
public:
    int currSize;
    int maxSize;
    map<int, list<vector<int>>> freq;
    unordered_map<int, list<vector<int>>::iterator> mp;
    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
    }
    
    void markFrequentlyUsed(int key) {
        auto& vec = (*(mp[key]));
        int value = vec[1];
        int count = vec[2];
        freq[count].erase(mp[key]);
        if (freq[count].empty()) {
            freq.erase(count);
        }
        count++;
        freq[count].push_front({key, value, count});
        mp[key] = freq[count].begin();
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        auto vec = (*(mp[key]));
        int value = vec[1];
        markFrequentlyUsed(key);
        return value;
    }
    
    void put(int key, int value) {
        if (maxSize == 0) return;
        if (mp.count(key)) {
            auto &listNode = (*(mp[key]));
            listNode[1] = value;
            markFrequentlyUsed(key);
        }
        else if (currSize < maxSize) {
            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();
            currSize++;
        }
        else {
            auto &listToManipulate = freq.begin()->second;
            int key_to_delete = listToManipulate.back()[0];
            listToManipulate.pop_back();
            if (listToManipulate.empty()) {
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front({key, value, 1});
            mp.erase(key_to_delete);
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */