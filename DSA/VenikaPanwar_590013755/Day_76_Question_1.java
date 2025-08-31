public class Day_76_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Converts tree to sum tree and returns sum of original subtree
    public static int toSumTree(TreeNode root) {
        if (root == null) return 0;
        int leftSum = toSumTree(root.left);
        int rightSum = toSumTree(root.right);
        int oldVal = root.val;
        root.val = leftSum + rightSum;
        return root.val + oldVal;
    }

    // Inorder traversal for demonstration
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        // Example tree: 10 / \ -2 6 / \ / \ 8 -4 7 5
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(-2);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(8);
        root.left.right = new TreeNode(-4);
        root.right.left = new TreeNode(7);
        root.right.right = new TreeNode(5);

        toSumTree(root);
        System.out.print("Sum Tree Inorder: ");
        inorder(root); // Output: 0 4 0 20 0 12 0
        System.out.println();
    }
}