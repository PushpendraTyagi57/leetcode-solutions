/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndex(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    int binarySearch(int low, int high, int target, MountainArray &mountainArr) {
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mountainArr.get(mid) == target) return mid;
            else if (mountainArr.get(mid) > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
    int reversedBinarySearch(int low, int high, int target, MountainArray &mountainArr) {
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mountainArr.get(mid) == target) return mid;
            else if (mountainArr.get(mid) > target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = peakIndex(mountainArr);
        int resultIdx = binarySearch(0, idx, target, mountainArr);
        if (resultIdx != -1) return resultIdx;
        resultIdx = reversedBinarySearch(idx + 1, n - 1, target, mountainArr);
        return resultIdx;
    }
};