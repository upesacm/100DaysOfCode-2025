import java.util.*;

public class Day_75_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Prints the right view of the binary tree
    public static void printRightView(TreeNode root) {
        if (root == null) return;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            TreeNode last = null;
            for (int i = 0; i < levelSize; i++) {
                last = queue.poll();
                if (last.left != null) queue.offer(last.left);
                if (last.right != null) queue.offer(last.right);
            }
            System.out.print(last.val + " "); // Last node at this level
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Example: Tree 1 / \ 2 3 / 4
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);

        System.out.print("Right View: ");
        printRightView(root); // Output: 1 3 4
    }
}