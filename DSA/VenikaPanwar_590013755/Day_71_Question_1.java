public class Day_71_Question_1 {

    // Definition for a binary tree node
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursive inorder traversal: left-root-right
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        // Example 1: Tree: 1 \ 3 / 2
        TreeNode root1 = new TreeNode(1);
        root1.right = new TreeNode(3);
        root1.right.left = new TreeNode(2);
        System.out.print("Inorder Traversal (Example 1): ");
        inorder(root1);
        System.out.println();

        // Example 2: Tree: 4 / \ 2 5
        TreeNode root2 = new TreeNode(4);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(5);
        System.out.print("Inorder Traversal (Example 2): ");
        inorder(root2);
        System.out.println();
    }
}
