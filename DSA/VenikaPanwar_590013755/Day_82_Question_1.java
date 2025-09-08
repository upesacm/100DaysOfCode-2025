public class Day_82_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Builds a balanced BST from sorted array
    public static TreeNode sortedArrayToBST(int[] arr) {
        return buildBST(arr, 0, arr.length - 1);
    }

    private static TreeNode buildBST(int[] arr, int left, int right) {
        if (left > right) return null;
        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(arr[mid]);
        root.left = buildBST(arr, left, mid - 1);
        root.right = buildBST(arr, mid + 1, right);
        return root;
    }

    // Preorder traversal for demonstration
    public static void preorder(TreeNode root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4, 5, 6, 7};
        TreeNode root1 = sortedArrayToBST(arr1);
        System.out.print("Preorder (Example 1): ");
        preorder(root1); // Output: 4 2 1 3 6 5 7
        System.out.println();

        int[] arr2 = {10, 20, 30, 40};
        TreeNode root2 = sortedArrayToBST(arr2);
        System.out.print("Preorder (Example 2): ");
        preorder(root2); // Output: 20 10 30 40
        System.out.println();
    }
}
