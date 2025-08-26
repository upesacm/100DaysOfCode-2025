import java.util.*;

// Definition of a binary tree node
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class Question2 {

    // Function to check if two trees are the same
    public static boolean isSameTree(TreeNode root1, TreeNode root2) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root1);
        queue.add(root2);

        while (!queue.isEmpty()) {
            TreeNode first = queue.poll();
            TreeNode second = queue.poll();

            // Both are null → continue
            if (first == null && second == null) {
                continue;
            }
            // If one is null or values don’t match → false
            if (first == null || second == null || first.val != second.val) {
                return false;
            }

            // Add children to queue
            queue.add(first.left);
            queue.add(second.left);
            queue.add(first.right);
            queue.add(second.right);
        }
        return true;
    }

    // Function to build tree from user input
    public static TreeNode buildTree(Scanner sc, int n) {
        if (n == 0) return null;

        TreeNode[] nodes = new TreeNode[n + 1];
        for (int i = 1; i <= n; i++) {
            System.out.print("Enter value of node " + i + ": ");
            int val = sc.nextInt();
            nodes[i] = new TreeNode(val);
        }

        // Build tree with child indices
        for (int i = 1; i <= n; i++) {
            System.out.print("Enter left child index of node " + i + " (0 if none): ");
            int left = sc.nextInt();
            if (left != 0) nodes[i].left = nodes[left];

            System.out.print("Enter right child index of node " + i + " (0 if none): ");
            int right = sc.nextInt();
            if (right != 0) nodes[i].right = nodes[right];
        }

        return nodes[1]; // assuming node 1 is root
    }

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes in first tree: ");
        int n1 = sc.nextInt();
        TreeNode root1 = buildTree(sc, n1);

        System.out.print("Enter number of nodes in second tree: ");
        int n2 = sc.nextInt();
        TreeNode root2 = buildTree(sc, n2);

        boolean result = isSameTree(root1, root2);

        if (result) {
            System.out.println("Both trees are identical.");
        } else {
            System.out.println("Trees are not identical.");
        }

        sc.close();
    }
}
