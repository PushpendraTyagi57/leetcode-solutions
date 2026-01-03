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
class Solution {
public:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* mergeSortedList(ListNode* leftHalf, ListNode* rightHalf) {
        if (leftHalf == NULL) return rightHalf;
        if (rightHalf == NULL) return leftHalf;
        ListNode* result;
        if (leftHalf -> val < rightHalf -> val) {
            result = leftHalf;
            result -> next = mergeSortedList(leftHalf -> next, rightHalf);
        }
        else {
            result = rightHalf;
            result -> next = mergeSortedList(leftHalf, rightHalf -> next);
        }
        return result;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode* mid = getMid (head);
        ListNode* newhead = mid -> next;
        mid -> next = NULL;

        ListNode* leftHalf = sortList(head);
        ListNode* rightHalf = sortList(newhead);
        return mergeSortedList(leftHalf, rightHalf);

    }
};