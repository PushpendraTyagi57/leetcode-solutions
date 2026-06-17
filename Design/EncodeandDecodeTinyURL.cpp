#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    int id = 1;
    string base62Encode(int num) {
        string res;
        while (num > 0) {
            res += chars[num % 62];
            num /= 62;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string encode(string longUrl) {
        if (longToShort.count(longUrl))
            return longToShort[longUrl];
        
        string code = base62Encode(id++);
        string shortUrl = "https://tinyurl.com/" + code;

        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));