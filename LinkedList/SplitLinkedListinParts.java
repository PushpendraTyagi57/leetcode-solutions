import java.util.*;

public class SplitLinkedListinParts {
    int val;
    SplitLinkedListinParts next;
    SplitLinkedListinParts() {}
    SplitLinkedListinParts(int val) { this.val = val; }
    SplitLinkedListinParts(int val, SplitLinkedListinParts next) { this.val = val; this.next = next; }
}
class Solution {
    public SplitLinkedListinParts[] splitListToParts(SplitLinkedListinParts head, int k) {
        SplitLinkedListinParts[] ans = new SplitLinkedListinParts[k];
        int L = 0;
        SplitLinkedListinParts curr = head;
        while (curr != null) {
            curr = curr.next;
            L++;
        }
        int eachBucketNodes = L / k;
        int extraNodes = L % k;
        curr = head;
        SplitLinkedListinParts prev = null;
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