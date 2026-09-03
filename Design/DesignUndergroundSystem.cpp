#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInMap; // {id -> {startStation, entryTime}}
    unordered_map<string, pair<int, int>> checkOutMap; // {route -> {totalTime, count}}
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkInMap[id].first;
        string endStation = stationName;
        string route = startStation + "_" + endStation;

        int startTime = checkInMap[id].second;
        int routeDuration = t - startTime;

        auto& it = checkOutMap[route];
        it.first += routeDuration;
        it.second += 1;
        checkInMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto& it = checkOutMap[route];
        int totalTime = it.first;
        int count = it.second;
        return (double) totalTime / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */