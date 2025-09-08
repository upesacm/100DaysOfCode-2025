public class Day_79_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursively counts nodes in BST
    public static int countNodes(TreeNode root) {
        if (root == null) return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    public static void main(String[] args) {
        // Example 1: Tree 5 / \ 3 7
        TreeNode root1 = new TreeNode(5);
        root1.left = new TreeNode(3);
        root1.right = new TreeNode(7);
        System.out.println("Node count (Example 1): " + countNodes(root1)); // Output: 3

        // Example 2: Tree 8 / \ 6 10 /
        TreeNode root2 = new TreeNode(8);
        root2.left = new TreeNode(6);
        root2.right = new TreeNode(10);
        root2.left.left = new TreeNode(4);
        System.out.println("Node count (Example 2): " + countNodes(root2)); // Output: 4
    }
}
