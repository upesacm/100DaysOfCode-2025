class Q3 {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    static int maxSum;

    public static int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        dfs(root);
        return maxSum;
    }

    private static int dfs(TreeNode node) {
        if (node == null) return 0;

        int left = Math.max(0, dfs(node.left));
        int right = Math.max(0, dfs(node.right));

        maxSum = Math.max(maxSum, node.val + left + right);

        return node.val + Math.max(left, right);
    }

    public static void main(String[] args) {
        // Example 1
        TreeNode root1 = new TreeNode(10);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(10);
        root1.left.left = new TreeNode(20);
        root1.left.right = new TreeNode(1);
        root1.right.right = new TreeNode(-25);
        root1.right.right.left = new TreeNode(3);
        root1.right.right.right = new TreeNode(4);

        System.out.println(maxPathSum(root1)); // Output: 42

        // Example 2
        TreeNode root2 = new TreeNode(-10);
        root2.left = new TreeNode(9);
        root2.right = new TreeNode(20);
        root2.right.left = new TreeNode(15);
        root2.right.right = new TreeNode(7);

        System.out.println(maxPathSum(root2)); // Output: 42
    }
}
