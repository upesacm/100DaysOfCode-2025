public class Day_72_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursively mirrors the binary tree
    public static void mirror(TreeNode root) {
        if (root == null) return;
        // Swap left and right children
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        // Recursively mirror subtrees
        mirror(root.left);
        mirror(root.right);
    }

    // Inorder traversal for demonstration
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        // Example: Tree 1 / \ 2 3
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        System.out.print("Original inorder: ");
        inorder(root);
        System.out.println();

        mirror(root);

        System.out.print("Mirrored inorder: ");
        inorder(root);
        System.out.println();
    }
}