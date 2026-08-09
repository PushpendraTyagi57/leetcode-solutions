/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ans = new ListNode[k];
        int L = 0;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            L++;
        }
        int eachBucketNodes = L / k;
        int extraNodes = L % k;
        curr = head;
        ListNode prev = null;
        for (int i = 0; i < k; i++) {
            ans[i] = curr;
            for (int count = 1; count <= eachBucketNodes + (extraNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr.next;
            }
            if (prev != null) prev.next = null;
            extraNodes--;
        }
        return ans;
    }
}