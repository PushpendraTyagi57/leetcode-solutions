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
    ListNode* reverseList(ListNode* first, ListNode* last) {
        ListNode* prev = NULL;
        ListNode* curr = first;
        while (curr != last) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* front = curr;
            int count = 1;
            while (front != NULL && count < k) {
                front = front->next;
                count++;
            }
            if (front == NULL || count != k) break;
            ListNode* nextCurr = front->next;
            ListNode* newHead = reverseList(curr, front->next);
            if (prev == NULL) head = newHead;
            else prev->next = newHead;
            prev = curr;
            curr->next = nextCurr;
            curr = nextCurr;
        }
        return head;
    }
};