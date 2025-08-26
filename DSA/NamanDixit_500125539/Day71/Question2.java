import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class Question2 {

    // Function to count nodes in a complete binary tree
    public static int countNodes(TreeNode root) {
        if (root == null) return 0;

        int leftDepth = leftDepth(root);
        int rightDepth = rightDepth(root);

        if (leftDepth == rightDepth) {
            return (int) Math.pow(2, leftDepth) - 1; // Perfect tree
        }

        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    private static int leftDepth(TreeNode root) {
        int dep = 0;
        while (root != null) {
            root = root.left;
            dep++;
        }
        return dep;
    }

    private static int rightDepth(TreeNode root) {
        int dep = 0;
        while (root != null) {
            root = root.right;
            dep++;
        }
        return dep;
    }

    // Build tree from user input (level order, -1 for null)
    public static TreeNode buildTreeFromInput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter node values in level order (use -1 for null):");

        int val = sc.nextInt();
        if (val == -1) return null;

        TreeNode root = new TreeNode(val);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            // Left child
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                current.left = new TreeNode(leftVal);
                queue.add(current.left);
            }

            // Right child
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                current.right = new TreeNode(rightVal);
                queue.add(current.right);
            }
        }

        return root;
    }

    public static void main(String[] args) {
        TreeNode root = buildTreeFromInput();
        int nodeCount = countNodes(root);
        System.out.println(nodeCount);
    }
}
