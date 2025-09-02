public class Day_73_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursively finds the maximum value in the binary tree
    public static int findMax(TreeNode root) {
        if (root == null) return Integer.MIN_VALUE;
        int leftMax = findMax(root.left);
        int rightMax = findMax(root.right);
        return Math.max(root.val, Math.max(leftMax, rightMax));
    }

    public static void main(String[] args) {
        // Example 1: Tree 3 / \ 2 5
        TreeNode root1 = new TreeNode(3);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(5);
        System.out.println("Max (Example 1): " + findMax(root1)); // Output: 5

        // Example 2: Tree 1 \ 9
        TreeNode root2 = new TreeNode(1);
        root2.right = new TreeNode(9);
        System.out.println("Max (Example 2): " + findMax(root2)); // Output: 9
    }
}
