// File: Question1.java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class Question1 {

    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) {
            return 0;
        }

        int sum = 0;

        // Explore the left sub-tree
        if (root.val > low) {
            sum += rangeSumBST(root.left, low, high);
        }

        // If value is in range add it to sum
        if (root.val >= low && root.val <= high) {
            sum += root.val;
        }

        // Explore the right sub-tree only if required
        if (root.val < high) {
            sum += rangeSumBST(root.right, low, high);
        }

        return sum;
    }

    // Insert node in BST
    public TreeNode insert(TreeNode root, int val) {
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question1 obj = new Question1();
        TreeNode root = null;

        // Input number of nodes
        System.out.print("Enter number of nodes in BST: ");
        int n = sc.nextInt();

        // Input node values
        System.out.println("Enter " + n + " node values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            root = obj.insert(root, val);
        }

        // Input range
        System.out.print("Enter low value: ");
        int low = sc.nextInt();
        System.out.print("Enter high value: ");
        int high = sc.nextInt();

        // Compute range sum
        int result = obj.rangeSumBST(root, low, high);
        System.out.println(result);

        sc.close();
    }
}
