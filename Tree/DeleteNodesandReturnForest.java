import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) {
        this.val = val;
    }
}

class Solution {
    HashSet<Integer> st;
    List<TreeNode> result;
    public TreeNode solve(TreeNode root) {
        if (root == null) return null;
        root.left = solve(root.left);
        root.right = solve(root.right);
        if (st.contains(root.val)) {
            if (root.left != null) {
                result.add(root.left);
            }
            if (root.right != null) {
                result.add(root.right);
            }
            return null;
        }
        else return root;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        st = new HashSet<>();
        for (int num : to_delete) st.add(num);
        result = new ArrayList<>();
        solve(root);
        if (!st.contains(root.val)) result.add(root);
        return result;
    }
}