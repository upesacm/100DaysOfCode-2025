public class Day_74_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Returns -1 if not balanced, else returns height
    private static int checkHeight(TreeNode root) {
        if (root == null) return 0;
        int left = checkHeight(root.left);
        int right = checkHeight(root.right);
        if (left == -1 || right == -1 || Math.abs(left - right) > 1) return -1;
        return Math.max(left, right) + 1;
    }

    public static boolean isBalanced(TreeNode root) {
        return checkHeight(root) != -1;
    }

    public static void main(String[] args) {
        // Example 1: Unbalanced tree 1 / 2 / 3
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.left.left = new TreeNode(3);
        System.out.println("Is balanced (Example 1): " + (isBalanced(root1) ? "Yes" : "No")); // Output: No

        // Example 2: Balanced tree 1 / \ 2 3
        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(3);
        System.out.println("Is balanced (Example 2): " + (isBalanced(root2) ? "Yes" : "No")); // Output: Yes
    }
}