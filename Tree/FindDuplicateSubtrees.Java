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

class findDuplicateSubtrees {
    List<TreeNode> result;
    HashMap<String, Integer> mp;
    public String getSubTreeString(TreeNode root) {
        if (root == null) return "N";
        String s = Integer.toString(root.val) + "," + 
                    getSubTreeString(root.left) + "," + 
                    getSubTreeString(root.right);
        if (mp.containsKey(s) && mp.get(s) == 1) result.add(root);
        if (mp.containsKey(s)) {
            mp.put(s, mp.get(s) + 1);
        }
        else {
            mp.put(s, 1);
        }
        return s;
    }
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        result = new ArrayList<>();
        mp = new HashMap<>();
        getSubTreeString(root);
        return result;
    }
    
    public static void main(String[] args) {
        
    }
}