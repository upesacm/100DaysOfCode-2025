public class Day_81_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Prints all nodes in [L, R] in sorted order
    public static void printNodesInRange(TreeNode root, int L, int R) {
        if (root == null) return;
        if (root.val > L) printNodesInRange(root.left, L, R);
        if (root.val >= L && root.val <= R) System.out.print(root.val + " ");
        if (root.val < R) printNodesInRange(root.right, L, R);
    }

    public static void main(String[] args) {
        // Example 1: Tree 10 / \ 5 15 / \ \ 3 7 18, L=7, R=15
        TreeNode root1 = new TreeNode(10);
        root1.left = new TreeNode(5);
        root1.right = new TreeNode(15);
        root1.left.left = new TreeNode(3);
        root1.left.right = new TreeNode(7);
        root1.right.right = new TreeNode(18);

        System.out.print("Nodes in range (7,15): ");
        printNodesInRange(root1, 7, 15); // Output: 7 10 15
        System.out.println();

        // Example 2: Tree 6 / \ 2 8 / \ / \ 0 4 7 9, L=2, R=8
        TreeNode root2 = new TreeNode(6);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(8);
        root2.left.left = new TreeNode(0);
        root2.left.right = new TreeNode(4);
        root2.right.left = new TreeNode(7);
        root2.right.right = new TreeNode(9);

        System.out.print("Nodes in range (2,8): ");
        printNodesInRange(root2, 2, 8); // Output: 2 4 6 7 8
        System.out.println();
    }
}
