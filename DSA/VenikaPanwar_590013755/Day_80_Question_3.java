public class Day_80_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Finds Kth smallest element in BST
    public static int kthSmallest(TreeNode root, int k) {
        int[] count = {0};
        int[] result = {0};
        kthSmallestHelper(root, k, count, result);
        return result[0];
    }

    private static void kthSmallestHelper(TreeNode root, int k, int[] count, int[] result) {
        if (root == null) return;
        kthSmallestHelper(root.left, k, count, result);
        count[0]++;
        if (count[0] == k) result[0] = root.val;
        kthSmallestHelper(root.right, k, count, result);
    }

    public static void main(String[] args) {
        // Example 1: Tree 3 / \ 1 4 \ 2, K=1
        TreeNode root1 = new TreeNode(3);
        root1.left = new TreeNode(1);
        root1.right = new TreeNode(4);
        root1.left.right = new TreeNode(2);
        System.out.println("Kth smallest (K=1): " + kthSmallest(root1, 1)); // Output: 1

        // Example 2: Tree 5 / \ 3 6 / \ 2 4 / 1, K=3
        TreeNode root2 = new TreeNode(5);
        root2.left = new TreeNode(3);
        root2.right = new TreeNode(6);
        root2.left.left = new TreeNode(2);
        root2.left.right = new TreeNode(4);
        root2.left.left.left = new TreeNode(1);
        System.out.println("Kth smallest (K=3): " + kthSmallest(root2, 3)); // Output: 3
    }
}
