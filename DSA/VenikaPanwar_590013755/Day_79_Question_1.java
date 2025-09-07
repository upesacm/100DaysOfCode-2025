public class Day_79_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Inorder traversal: left-root-right (prints sorted order for BST)
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        // Example 1: Tree 5 / \ 3 7 / \ 2 4
        TreeNode root1 = new TreeNode(5);
        root1.left = new TreeNode(3);
        root1.right = new TreeNode(7);
        root1.left.left = new TreeNode(2);
        root1.left.right = new TreeNode(4);

        System.out.print("Inorder (Example 1): ");
        inorder(root1); // Output: 2 3 4 5 7
        System.out.println();

        // Example 2: Tree 10 / \ 8 12
        TreeNode root2 = new TreeNode(10);
        root2.left = new TreeNode(8);
        root2.right = new TreeNode(12);

        System.out.print("Inorder (Example 2): ");
        inorder(root2); // Output: 8 10 12
        System.out.println();
    }
}
