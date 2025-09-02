import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Question2 {

    // Function to build tree from user input (level order)
    public static TreeNode buildTree(Scanner sc) {
        System.out.println("Enter root value (-1 for null):");
        int rootVal = sc.nextInt();
        if (rootVal == -1) return null;

        TreeNode root = new TreeNode(rootVal);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            System.out.println("Enter left child of " + current.val + " (-1 for null):");
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                current.left = new TreeNode(leftVal);
                queue.offer(current.left);
            }

            System.out.println("Enter right child of " + current.val + " (-1 for null):");
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                current.right = new TreeNode(rightVal);
                queue.offer(current.right);
            }
        }
        return root;
    }

    // Main function to check if tree is balanced
    public static boolean isBalanced(TreeNode root) {
        return getHeight(root) != -1;
    }

    // Helper function: post-order traversal to compute height
    private static int getHeight(TreeNode root) {
        if (root == null) return 0;

        int leftSubtreeHeight = getHeight(root.left);
        int rightSubtreeHeight = getHeight(root.right);

        if (leftSubtreeHeight == -1 || rightSubtreeHeight == -1) return -1;
        if (Math.abs(leftSubtreeHeight - rightSubtreeHeight) > 1) return -1;

        return 1 + Math.max(leftSubtreeHeight, rightSubtreeHeight);
    }

    // Driver code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree
        TreeNode root = buildTree(sc);

        // Check if balanced
        if (isBalanced(root)) {
            System.out.println("The binary tree is balanced.");
        } else {
            System.out.println("The binary tree is not balanced.");
        }
    }
}
