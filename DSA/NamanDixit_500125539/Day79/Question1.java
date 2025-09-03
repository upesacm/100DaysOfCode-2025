import java.util.*;

// Definition of TreeNode
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class Question1 {

    // Function to insert nodes in BST
    public static TreeNode insert(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (val < root.val) {
            root.left = insert(root.left, val);
        } else {
            root.right = insert(root.right, val);
        }
        return root;
    }

    // Function for Inorder Traversal
    public static void inorderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left);
        System.out.print(root.val + " ");
        inorderTraversal(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input for BST
        System.out.print("Enter number of nodes in BST: ");
        int n = sc.nextInt();
        TreeNode root = null;

        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            root = insert(root, val);
        }

        // Printing inorder traversal
        System.out.println("Inorder Traversal of BST:");
        inorderTraversal(root);

        sc.close();
    }
}
