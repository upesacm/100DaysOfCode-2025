public class Day_71_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursive leaf counting
    public static int countLeaves(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        return countLeaves(root.left) + countLeaves(root.right);
    }

    public static void main(String[] args) {
        // Example 1: Tree: 1 / \ 2 3
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);
        System.out.println("Leaf count (Example 1): " + countLeaves(root1));

        // Example 2: Tree: 10 \ 20 / 15
        TreeNode root2 = new TreeNode(10);
        root2.right = new TreeNode(20);
        root2.right.left = new TreeNode(15);
        System.out.println("Leaf count (Example 2): " + countLeaves(root2));
    }
}
