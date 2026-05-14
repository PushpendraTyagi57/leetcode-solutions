#include <bits/stdc++.h>

using namespace std;


class Twitter {
public:
    priority_queue<vector<int>> pq;
    int time = 0;
    unordered_map<int, vector<vector<int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> pq;
        for (auto& tweet : tweets[userId]) {
            pq.push(tweet);
        }
        for (int followee : following[userId]) {
            for (auto& tweet : tweets[followee]) pq.push(tweet);
        }
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */