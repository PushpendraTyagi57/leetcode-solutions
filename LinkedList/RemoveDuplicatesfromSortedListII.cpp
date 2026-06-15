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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* front = head;
        while (front != NULL) {
            if (front->next != NULL && front->val == front->next->val) {
                int val = front->val;
                while (front != NULL && front->val == val) {
                    front = front->next;
                }
                prev->next = front;
            }
            else {
                prev = front;
                front = front->next;
            }
        }
        return dummy->next;
    }
};