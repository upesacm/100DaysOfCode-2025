public class Day_76_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Prints ancestors of target node
    public static boolean printAncestors(TreeNode root, int target) {
        if (root == null) return false;
        if (root.val == target) return true;
        if (printAncestors(root.left, target) || printAncestors(root.right, target)) {
            System.out.print(root.val + " ");
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        // Example tree: 1 / \ 2 3 /
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);

        System.out.print("Ancestors of 4: ");
        printAncestors(root, 4); // Output: 2 1
        System.out.println();
    }
}