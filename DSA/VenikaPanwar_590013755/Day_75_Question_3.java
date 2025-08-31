public class Day_75_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Helper class to store diameter
    static class Diameter {
        int value = 0;
    }

    // Returns height and updates diameter
    private static int diameterHelper(TreeNode root, Diameter d) {
        if (root == null) return 0;
        int left = diameterHelper(root.left, d);
        int right = diameterHelper(root.right, d);
        d.value = Math.max(d.value, left + right + 1);
        return Math.max(left, right) + 1;
    }

    public static int diameter(TreeNode root) {
        Diameter d = new Diameter();
        diameterHelper(root, d);
        return d.value;
    }

    public static void main(String[] args) {
        // Example: Tree 1 / \ 2 3 / \ 4 5
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.println("Diameter: " + (diameter(root))); // Output: 4