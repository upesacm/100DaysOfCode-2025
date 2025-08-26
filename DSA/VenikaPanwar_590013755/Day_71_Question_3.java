public class Day_71_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Recursive height calculation
    public static int treeHeight(TreeNode root) {
        if (root == null) return 0;
        int leftHeight = treeHeight(root.left);
        int rightHeight = treeHeight(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static void main(String[] args) {
        // Example 1: Tree: 1 / 2 / 3
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.left.left = new TreeNode(3);
        System.out.println("Height (Example 1): " + treeHeight(root1));

        // Example 2: Tree: 1 / \ 2 3
        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(3);
        System.out.println("Height (Example 2): " + treeHeight(root2));

        // Example 3: Tree: 1 / 2 / \ 3 4
        TreeNode root3 = new TreeNode(1);
        root3.left = new TreeNode(2);
        root3.left.right = new TreeNode(3);
        root3.right = new TreeNode(4);
        System.out.println("Height (Example 3): " + treeHeight(root3));
    }
}
