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
    public void traversalAlgorithm(TreeNode root, List<Integer> arr) {
        if (root == null) return;

        traversalAlgorithm(root.left, arr);
        traversalAlgorithm(root.right, arr);
        arr.add(root.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        // TC:O(N), SC:O(N, Recursive stack space)
        List<Integer> arr = new ArrayList<Integer>();

        traversalAlgorithm(root, arr);

        return arr;
    }
}

/******************************************************************************************************************/

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        // TC:O(N), SC:O(1)

        List<Integer> arr = new ArrayList<Integer>();
        if (root == null) return arr;

        Stack<TreeNode> st = new Stack();

        // This is preOrderTraversal
        st.push(root);
        while(!st.isEmpty()) {
            TreeNode curr = st.pop();
            arr.add(curr.val);
            if (curr.left != null) st.push(curr.left);
            if (curr.right != null) st.push(curr.right);
        }

        // This is done to get postOrderTraversal
        Collections.reverse(arr);

        return arr;
    }
}
