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

    public static void inOrderTraversal(TreeNode root) {
        if (root == null)
            return;

        inOrderTraversal(root.left);
        System.out.print(root.val + " -> ");
        inOrderTraversal(root.right);
    }

    // Function to build tree from user input (level order)
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
        System.out.println("Inorder Traversal of Tree:");
        inOrderTraversal(root);
    }
}
