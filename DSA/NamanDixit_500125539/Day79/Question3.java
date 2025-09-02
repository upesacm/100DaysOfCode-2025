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

public class Question3 {

    // Insert nodes in BST
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

    // Function to check if tree is a valid BST
    public static boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private static boolean isValidBST(TreeNode root, long minVal, long maxVal) {
        if (root == null) return true;

        if (root.val <= minVal || root.val >= maxVal) return false;

        return isValidBST(root.left, minVal, root.val) &&
               isValidBST(root.right, root.val, maxVal);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input
        System.out.print("Enter number of nodes in tree: ");
        int n = sc.nextInt();
        TreeNode root = null;

        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            root = insert(root, val);
        }

        // Checking if valid BST
        if (isValidBST(root)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        sc.close();
    }
}
