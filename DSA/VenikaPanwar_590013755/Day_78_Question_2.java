public class Day_78_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Inserts a value into BST and returns new root
    public static TreeNode insertBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insertBST(root.left, val);
        else root.right = insertBST(root.right, val);
        return root;
    }

    // Inorder traversal for demonstration
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        // Example: Tree 5 / \ 3 7, Insert 4
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(7);

        root = insertBST(root, 4);
        System.out.print("Inorder after insert: ");
        inorder(root); // Output: 3 4 5 7
        System.out.println();

        // Example: Tree 10, Insert 20
        TreeNode root2 = new TreeNode(10);
        root2 = insertBST(root2, 20);
        System.out.print("Inorder after insert: ");
        inorder(root2); // Output: 10 20
        System.out.println();
    }
}
