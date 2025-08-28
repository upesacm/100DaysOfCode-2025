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

public class Question3 {

    // Build tree from user input (level order)
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

    // Recursive function to print all root-to-leaf paths
    public static void printPaths(TreeNode root, List<Integer> path) {
        if (root == null) return;

        path.add(root.val);

        // If leaf node, print the path
        if (root.left == null && root.right == null) {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) System.out.print("->");
                System.out.print(path.get(i));
            }
            System.out.println();
        } else {
            // Continue searching
            printPaths(root.left, path);
            printPaths(root.right, path);
        }

        // Backtrack
        path.remove(path.size() - 1);
    }

    // Driver code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree from input
        TreeNode root = buildTree(sc);

        printPaths(root, new ArrayList<>());
    }
}
