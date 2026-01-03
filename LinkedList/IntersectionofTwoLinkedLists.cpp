/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0;
        int lenB = 0;
        while (tempA != NULL || tempB != NULL) {
            if (tempA != NULL) {
                tempA = tempA -> next;
                lenA++;
            }
            if (tempB != NULL) {
                tempB = tempB -> next;
                lenB++;
            }
        }
        if (lenA > lenB) {
            while (lenA - lenB != 0) {
                headA = headA -> next;
                lenA--;
            }
        }
        else if (lenA < lenB) {
            while (lenB - lenA != 0) {
                headB = headB -> next;
                lenB--;
            }
        }
        while (headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        if (headA == headB) return headA;
        return NULL;
    }
};