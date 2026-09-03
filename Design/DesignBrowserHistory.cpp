#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
public:
    vector<string> vec;
    int idx;
    BrowserHistory(string homepage) {
        vec.push_back(homepage);
        idx = 0;
    }
    
    void visit(string url) {
        vec.resize(idx + 1);
        vec.push_back(url);
        idx++;
    }
    
    string back(int steps) {
        idx = max(0, idx - steps);
        return vec[idx];
    }
    
    string forward(int steps) {
        idx = min((int) vec.size() - 1, idx + steps);
        return vec[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */