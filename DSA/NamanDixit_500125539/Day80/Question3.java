import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

class Solution {
    int count = 0;

    public int kthSmallest(TreeNode root, int k) {
        if (root == null) return -1;

        // Search in left subtree
        int left = kthSmallest(root.left, k);
        if (left != -1) return left;

        // Visit current node
        count++;
        if (count == k) return root.val;

        // Search in right subtree
        return kthSmallest(root.right, k);
    }
}

public class Question3 {

    // Function to insert node in BST
    public static TreeNode insert(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) {
            root.left = insert(root.left, val);
        } else {
            root.right = insert(root.right, val);
        }
        return root;
    }

    // Inorder traversal (for checking tree)
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        TreeNode root = null;
        Solution sol = new Solution();

        System.out.print("Enter number of nodes in BST: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            root = insert(root, val);
        }

        System.out.print("Inorder traversal of BST: ");
        inorder(root);
        System.out.println();

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        int ans = sol.kthSmallest(root, k);

        if (ans != -1) {
            System.out.println(k + "th smallest element is: " + ans);
        } else {
            System.out.println("Invalid k. Tree has fewer nodes.");
        }

        sc.close();
    }
}
