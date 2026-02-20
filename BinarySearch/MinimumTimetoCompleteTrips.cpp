class Solution {
public:
    bool possible(vector<int>& time, long long givenTime, int totalTrips) {
        long long possibleTrips = 0;
        for (int &t : time)
            possibleTrips += givenTime / t;
        return possibleTrips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = (long long) *min_element(time.begin(), time.end()) * totalTrips;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (possible(time, mid, totalTrips))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};