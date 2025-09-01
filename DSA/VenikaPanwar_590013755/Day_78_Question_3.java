public class Day_78_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Finds minimum value in BST
    public static int findMin(TreeNode root) {
        if (root == null) throw new IllegalArgumentException("Tree is empty");
        while (root.left != null) root = root.left;
        return root.val;
    }

    // Finds maximum value in BST
    public static int findMax(TreeNode root) {
        if (root == null) throw new IllegalArgumentException("Tree is empty");
        while (root.right != null) root = root.right;
        return root.val;
    }

    public static void main(String[] args) {
        // Example: Tree 8 / \ 3 10 / \ \ 1 6 14
        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(3);
        root.right = new TreeNode(10);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(6);
        root.right.right = new TreeNode(14);

        System.out.println("Min: " + findMin(root) + ", Max: " + findMax(root)); // Output: Min = 1, Max = 14

        // Example: Tree 5
        TreeNode root2 = new TreeNode(5);
        System.out.println("Min: " + findMin(root2) + ", Max: " + findMax(root2)); // Output: Min = 5, Max = 5
    }
}
