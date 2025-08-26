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

public class Question1 {

    // Recursive function to mirror (invert) a binary tree
    public static TreeNode mirrorTree(TreeNode root) {
        if (root == null) return null;

        // Swap left and right subtrees
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        // Recurse for left and right subtrees
        mirrorTree(root.left);
        mirrorTree(root.right);

        return root;
    }

    // Function to print the tree in level order (for testing)
    public static void printLevelOrder(TreeNode root) {
        if (root == null) return;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            System.out.print(node.val + " ");

            if (node.left != null) q.add(node.left);
            if (node.right != null) q.add(node.right);
        }
        System.out.println();
    }

    // Main method: take inputs from the user
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n == 0) {
            System.out.println("Tree is empty.");
            return;
        }

        TreeNode[] nodes = new TreeNode[n + 1];
        for (int i = 1; i <= n; i++) {
            System.out.print("Enter value of node " + i + ": ");
            int val = sc.nextInt();
            nodes[i] = new TreeNode(val);
        }

        // Build tree: user provides indices of children
        for (int i = 1; i <= n; i++) {
            System.out.print("Enter left child index of node " + i + " (0 if none): ");
            int left = sc.nextInt();
            if (left != 0) nodes[i].left = nodes[left];

            System.out.print("Enter right child index of node " + i + " (0 if none): ");
            int right = sc.nextInt();
            if (right != 0) nodes[i].right = nodes[right];
        }

        TreeNode root = nodes[1]; // root is node 1

        System.out.println("Original Tree (Level Order): ");
        printLevelOrder(root);

        root = mirrorTree(root);

        System.out.println("Mirrored Tree (Level Order): ");
        printLevelOrder(root);

        sc.close();
    }
}
