/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        vector<int> vec;
        ListNode* temp = head;
        while (temp != NULL) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int n = vec.size();
        int start = 0, group = 1;
        while (start < n) {
            int remaining = n - start;
            int len = min(group, remaining);
            if (len % 2 == 0)
                reverse(vec.begin() + start, vec.begin() + start + len);
            start += len;
            group++;
        }
        temp = head;
        for (int i = 0; i < n; i++) {
            temp->val = vec[i];
            temp = temp->next;
        }
        return head;
    }
};