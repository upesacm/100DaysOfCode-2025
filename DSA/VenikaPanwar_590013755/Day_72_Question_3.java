public class Day_72_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursively counts the total number of nodes
    public static int countNodes(TreeNode root) {
        if (root == null) return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    public static void main(String[] args) {
        // Example 1: Tree 1 / \ 2 3
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);
        System.out.println("Node count (Example 1): " + countNodes(root1));

        // Example 2: Tree 5 \ 6
        TreeNode root2 = new TreeNode(5);
        root2.right = new TreeNode(6);
        System.out.println("Node count (Example 2): " + countNodes(root2));
    }
}
