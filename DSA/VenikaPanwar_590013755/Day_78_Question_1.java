public class Day_78_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Searches for a key in BST
    public static boolean searchBST(TreeNode root, int key) {
        if (root == null) return false;
        if (root.val == key) return true;
        if (key < root.val) return searchBST(root.left, key);
        else return searchBST(root.right, key);
    }

    public static void main(String[] args) {
        // Example: Tree 5 / \ 3 7 / \ / \ 2 4 6 8
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(8);

        int key1 = 4, key2 = 10;
        System.out.println("Search 4: " + (searchBST(root, key1) ? "Yes" : "No")); // Output: Yes
        System.out.println("Search 10: " + (searchBST(root, key2) ? "Yes" : "No")); // Output: No
    }
}