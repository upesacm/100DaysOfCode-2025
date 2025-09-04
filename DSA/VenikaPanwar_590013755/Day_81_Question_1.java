public class Day_81_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Returns sum of values in [L, R] using pruned traversal
    public static int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) return 0;
        if (root.val < L) return rangeSumBST(root.right, L, R);
        if (root.val > R) return rangeSumBST(root.left, L, R);
        return root.val + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
    }

    public static void main(String[] args) {
        // Example 1: Tree 10 / \ 5 15 / \ \ 3 7 18, L=7, R=15
        TreeNode root1 = new TreeNode(10);
        root1.left = new TreeNode(5);
        root1.right = new TreeNode(15);
        root1.left.left = new TreeNode(3);
        root1.left.right = new TreeNode(7);
        root1.right.right = new TreeNode(18);
        System.out.println("Range Sum (7,15): " + rangeSumBST(root1, 7, 15)); // Output: 32

        // Example 2: Tree 10 / \ 5 15 / \ / \ 3 7 13 18, L=6, R=10
        TreeNode root2 = new TreeNode(10);
        root2.left = new TreeNode(5);
        root2.right = new TreeNode(15);
        root2.left.left = new TreeNode(3);
        root2.left.right = new TreeNode(7);
        root2.right.left = new TreeNode(13);
        root2.right.right = new TreeNode(18);
        System.out.println("Range Sum (6,10): " + rangeSumBST(root2, 6, 10)); // Output: 17
    }
}