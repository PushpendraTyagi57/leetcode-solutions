/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;

class widthOfBinaryTree {
    class Pair {
        TreeNode first;
        int second;
        Pair(TreeNode first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public int widthOfBinaryTree(TreeNode root) {
        Deque<Pair> que = new ArrayDeque<>();
        que.offerLast(new Pair(root, 0));
        int maxWidth = 0;
        while (!que.isEmpty()) {
            int n = que.size();
            int L = que.peekFirst.second;
            int R = que.peekLast.second;
            maxWidth = max(maxWidth, R - L + 1);
            while (n--) {
                TreeNode curr = que.peekFirst().first;
                int idx = que.peekFirst().second;
                que.poll();
                if (curr.left) que.offerLast(new Pair(curr.left, 2 * idx + 1));
                if (curr.right) que.offerLast(new Pair(curr.right, 2 * idx + 2));
            }
        }
        return maxWidth;
    }
}