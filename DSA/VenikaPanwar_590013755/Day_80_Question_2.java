public class Day_80_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Deletes a node from BST and returns new root
    public static TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (key < root.val) root.left = deleteNode(root.left, key);
        else if (key > root.val) root.right = deleteNode(root.right, key);
        else {
            // Node found
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            // Node with two children: replace with inorder successor
            TreeNode succ = root.right;
            while (succ.left != null) succ = succ.left;
            root.val = succ.val;
            root.right = deleteNode(root.right, succ.val);
        }
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
        // Example: Tree 5 / \ 3 6 / \ 2 4, Delete 3
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(4);

        root = deleteNode(root, 3);
        System.out.print("Inorder after delete: ");
        inorder(root); // Output: 2 4 5 6
        System.out.println();

        // Example: Tree 10 / \ 5 15, Delete 10
        TreeNode root2 = new TreeNode(10);
        root2.left = new TreeNode(5);
        root2.right = new TreeNode(15);

        root2 = deleteNode(root2, 10);
        System.out.print("Inorder after delete: ");
        inorder(root2); // Output: 5 15
        System.out.println();
    }
}
