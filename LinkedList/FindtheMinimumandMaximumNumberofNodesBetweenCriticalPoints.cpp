#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIndex = -1;
        int lastIndex = -1;
        int index = 1;
        int prevSeenIndex = -1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int minDistance = INT_MAX;
        while (curr->next != NULL) {
            if (curr->val < prev->val && curr->val < curr->next->val) {
                if (prevSeenIndex != -1) {
                    minDistance = min(minDistance, index - prevSeenIndex);
                }
                if (firstIndex == -1) firstIndex = index;
                lastIndex = index;
                prevSeenIndex = index;
            }
            else if (curr->val > prev->val && curr->val > curr->next->val) {
                if (prevSeenIndex != -1) {
                    minDistance = min(minDistance, index - prevSeenIndex);
                }
                if (firstIndex == -1) firstIndex = index;
                lastIndex = index;
                prevSeenIndex = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        int maxDistance = (lastIndex - firstIndex == 0 ? -1 : lastIndex - firstIndex);
        minDistance = (minDistance == INT_MAX ? -1 : minDistance);
        return {minDistance, maxDistance};
    }
};