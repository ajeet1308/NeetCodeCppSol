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
class Solution {

    public void inorderTraversal(TreeNode root, List<Integer>arr) {
        if (root == null) return ;

        // Left -> Root -> Right
        inorderTraversal(root.left, arr);
        arr.add(root.val);
        inorderTraversal(root.right, arr);
    };

    public List<Integer> inorderTraversal(TreeNode root) {
        // TC:O(N), SC:O(N : Recursive Stack Space)
        List<Integer> arr = new ArrayList<Integer>();
        // Since ArrayList is public class and arr is an object copy of this class so we do not incurr with problem of pass by value, here by default it would be passed by reference

        inorderTraversal(root, arr);
        return arr;
    }
}

/**********************************************************************************************************************************/

class Solution {

    public List<Integer> inorderTraversal(TreeNode root) {
        // TC:O(N), SC:O(N)
        List<Integer> arr = new ArrayList<Integer>();
        // Since ArrayList is public class and arr is an object copy of this class so we do not incurr with problem of pass by value, here by default it would be passed by reference

        Stack<TreeNode> st = new Stack(); // LIFO

        while(!st.isEmpty() || root != null) {
            while(root != null) {
                st.push(root);
                root = root.left;
            }
            root = st.pop();
            arr.add(root.val);
            root = root.right;
        }

        return arr;
    }
}
