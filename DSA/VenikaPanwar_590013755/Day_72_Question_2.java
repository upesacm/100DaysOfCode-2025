public class Day_72_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursively checks if two trees are identical
    public static boolean isIdentical(TreeNode a, TreeNode b) {
        if (a == null && b == null) return true;
        if (a == null || b == null) return false;
        return a.val == b.val &&
               isIdentical(a.left, b.left) &&
               isIdentical(a.right, b.right);
    }

    public static void main(String[] args) {
        // Example 1: Identical trees
        TreeNode t1 = new TreeNode(1);
        t1.left = new TreeNode(2);
        t1.right = new TreeNode(3);

        TreeNode t2 = new TreeNode(1);
        t2.left = new TreeNode(2);
        t2.right = new TreeNode(3);

        System.out.println("Example 1: " + (isIdentical(t1, t2) ? "Yes" : "No"));

        // Example 2: Not identical
        TreeNode t3 = new TreeNode(1);
        t3.left = new TreeNode(2);

        TreeNode t4 = new TreeNode(1);
        t4.right = new TreeNode(2);

        System.out.println("Example 2: " + (isIdentical(t3, t4) ? "Yes" : "No"));
    }
}
