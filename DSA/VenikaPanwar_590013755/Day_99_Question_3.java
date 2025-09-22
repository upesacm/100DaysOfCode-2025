public class Day_99_Question_3 {

    // Definition for a binary tree node.
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }

    // Helper class to store the result
    static class Result {
        int maxPathSum; // max path sum anywhere in the tree
        int maxDown;    // max path sum from this node down to any node
        Result(int maxPathSum, int maxDown) {
            this.maxPathSum = maxPathSum;
            this.maxDown = maxDown;
        }
    }

    // Main function to find the maximum path sum
    public static int maxPathSum(TreeNode root) {
        return helper(root).maxPathSum;
    }

    // Helper function returns Result object for each subtree
    private static Result helper(TreeNode node) {
        if (node == null) return new Result(Integer.MIN_VALUE, 0);

        Result left = helper(node.left);
        Result right = helper(node.right);

        // Max path down from this node (can only go one direction)
        int maxDown = Math.max(Math.max(left.maxDown, right.maxDown), 0) + node.val;

        // Max path sum anywhere in this subtree
        int maxPathSum = Math.max(
            Math.max(left.maxPathSum, right.maxPathSum),
            left.maxDown + node.val + right.maxDown
        );

        return new Result(maxPathSum, maxDown);
    }

    // Example usage
    public static void main(String[] args) {
        // Example 1:
        //      10
        //     /  \
        //    2   10
        //   / \    \
        // 20   1   -25
        //           / \
        //          3   4
        TreeNode root1 = new TreeNode(10);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(10);
        root1.left.left = new TreeNode(20);
        root1.left.right = new TreeNode(1);
        root1.right.right = new TreeNode(-25);
        root1.right.right.left = new TreeNode(3);
        root1.right.right.right = new TreeNode(4);
        System.out.println(maxPathSum(root1)); // Output: 42

        // Example 2:
        //    -10
        //    /  \
        //   9   20
        //      /  \
        //     15   7
        TreeNode root2 = new TreeNode(-10);
        root2.left = new TreeNode(9);
        root2.right = new TreeNode(20);
        root2.right.left = new TreeNode(15);
        root2.right.right = new TreeNode(7);
        System.out.println(maxPathSum(root2)); // Output: 42
    }
}
