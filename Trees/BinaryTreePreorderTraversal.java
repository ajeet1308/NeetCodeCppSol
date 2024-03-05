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
    public void preOrderTraversal(TreeNode root, List<Integer>arr) {
        if (root == null) return;

        arr.add(root.val);
        preOrderTraversal(root.left, arr);
        preOrderTraversal(root.right, arr);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        // TC: O(N), SC:O(N)
        List<Integer> arr = new ArrayList<Integer>();

        preOrderTraversal(root, arr);
        return arr;
    }
}

/***************************************************************************************************************************/

class Solution {

    public List<Integer> preorderTraversal(TreeNode root) {
        // TC: O(N), SC:O(1)
        List<Integer> arr = new ArrayList<Integer>();

        Stack<TreeNode> st = new Stack();

        while(!st.empty() || root != null) {
            while(root != null) {
              
                arr.add(root.val); // Add root val bofore moving left or right
              
                st.push(root);
                root = root.left;
            }

            root = st.pop();
            root = root.right;
        }
        
        return arr;
    }
}
