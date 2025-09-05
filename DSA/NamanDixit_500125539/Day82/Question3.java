// Filename: Question2.java

import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class Question3 {
    int sum = 0;

    // Function to convert BST to Greater Tree
    public TreeNode convertBST(TreeNode root) {
        if (root != null) {
            convertBST(root.right);
            sum += root.val;
            root.val = sum;
            convertBST(root.left);
        }
        return root;
    }

    // Preorder traversal to print the tree
    public void preorder(TreeNode root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Example input
        // BST: [5, 2, 13]
        // After conversion: [18, 20, 13]

        Question3 solution = new Question3();

        // Constructing BST manually for demo
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(2);
        root.right = new TreeNode(13);
        // Convert BST
        solution.convertBST(root);

        System.out.println("\nGreater Tree (Preorder Traversal):");
        solution.preorder(root);

        sc.close();
    }
}
