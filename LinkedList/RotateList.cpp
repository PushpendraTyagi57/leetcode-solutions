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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL || head -> next == NULL) return head;
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            temp = temp -> next;
            length++;
        }
        k = k % length;
        if (k == 0) return head;
        int stepsToTake = length - k - 1;
        temp = head;
        while (stepsToTake > 0) {
            temp = temp -> next;
            stepsToTake--;
        }
        ListNode* newHead = temp -> next;
        temp -> next = NULL;
        ListNode* temp2 = newHead;
        while (temp2 -> next != NULL) {
            temp2 = temp2 -> next;
        }
        temp2 -> next = head;
        return newHead;
    }
};