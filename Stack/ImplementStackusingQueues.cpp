#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int n = que.size();
        for (int i = 0; i < n -1; i++) {
            que.push(que.front());
            que.pop();
        }
        int x = que.front();
        que.pop();
        return x;
    }
    
    int top() {
        int n = que.size();
        for (int i = 0; i < n - 1; i++) {
            que.push(que.front());
            que.pop();
        }
        int x = que.front();
        que.pop();
        que.push(x);
        return x;
    }
    
    bool empty() {
        if (que.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */