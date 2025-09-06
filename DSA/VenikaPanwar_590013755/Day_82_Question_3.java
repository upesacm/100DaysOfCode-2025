public class Day_82_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Converts BST to Greater Tree
    public static void convertBST(TreeNode root) {
        int[] sum = {0};
        reverseInorder(root, sum);
    }

    private static void reverseInorder(TreeNode root, int[] sum) {
        if (root == null) return;
        reverseInorder(root.right, sum);
        sum[0] += root.val;
        root.val = sum[0];
        reverseInorder(root.left, sum);
    }

    // Inorder traversal for demonstration
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        // Example 1: Tree 5 / \ 2 13
        TreeNode root1 = new TreeNode(5);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(13);
        convertBST(root1);
        System.out.print("Greater Tree Inorder (Example 1): ");
        inorder(root1); // Output: 20 18 13
        System.out.println();

        // Example 2: Tree 2 / \ 0 3 / \ -4 1
        TreeNode root2 = new TreeNode(2);
        root2.left = new TreeNode(0);
        root2.right = new TreeNode(3);
        root2.left.left = new TreeNode(-4);
        root2.left.right = new TreeNode(1);
        convertBST(root2);
        System.out.print("Greater Tree Inorder (Example 2): ");
        inorder(root2); // Output: 2 6 5 3 3
        System.out.println();
    }
}
