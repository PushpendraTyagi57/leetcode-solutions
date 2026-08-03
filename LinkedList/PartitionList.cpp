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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* smallPtr = small;
        ListNode* largePtr = large;
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->val < x) {
                smallPtr->next = temp;
                smallPtr = smallPtr->next;
            }
            else {
                largePtr->next = temp;
                largePtr = largePtr->next;
            }
            temp = temp->next;
        }
        smallPtr->next = large->next;
        largePtr->next = NULL;
        return small->next;
    }
};

int main () {
    
}