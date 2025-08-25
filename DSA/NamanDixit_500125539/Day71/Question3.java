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

    // Function to calculate height of binary tree using BFS
    public static int height(TreeNode root) {
        if (root == null) return 0;

        Queue<TreeNode> elementQueue = new LinkedList<>();
        elementQueue.add(root);
        int numberOfLevels = 0;

        while (true) {
            int nodeCountAtLevel = elementQueue.size();
            if (nodeCountAtLevel == 0) {
                return numberOfLevels;
            }

            // Process all nodes at the current level
            while (nodeCountAtLevel > 0) {
                TreeNode element = elementQueue.poll();
                if (element.left != null) {
                    elementQueue.add(element.left);
                }
                if (element.right != null) {
                    elementQueue.add(element.right);
                }
                nodeCountAtLevel--;
            }

            numberOfLevels++;
        }
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
        int h = height(root);
        System.out.println(h);
    }
}
