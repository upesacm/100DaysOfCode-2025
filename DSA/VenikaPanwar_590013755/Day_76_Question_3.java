public class Day_76_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Counts nodes at given level (root is level 1)
    public static int countAtLevel(TreeNode root, int level) {
        if (root == null) return 0;
        if (level == 1) return 1;
        return countAtLevel(root.left, level - 1) + countAtLevel(root.right, level - 1);
    }

    public static void main(String[] args) {
        // Example tree: 1 / \ 2 3 /
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);

        int level = 2;
        System.out.println("Nodes at level " + level + ": " + countAtLevel(root, level)); // Output: 2
    }
}