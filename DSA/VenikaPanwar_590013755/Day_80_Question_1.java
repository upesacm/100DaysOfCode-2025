public class Day_80_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Finds LCA of two nodes in BST
    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (p.val < root.val && q.val < root.val)
            return lowestCommonAncestor(root.left, p, q);
        if (p.val > root.val && q.val > root.val)
            return lowestCommonAncestor(root.right, p, q);
        return root;
    }

    public static void main(String[] args) {
        // Example: Tree 6 / \ 2 8 / \ / \ 0 4 7 9
        TreeNode root = new TreeNode(6);
        root.left = new TreeNode(2);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(0);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(7);
        root.right.right = new TreeNode(9);

        TreeNode p1 = root.left; // 2
        TreeNode q1 = root.right; // 8
        System.out.println("LCA of 2 and 8: " + lowestCommonAncestor(root, p1, q1).val); // Output: 6

        TreeNode p2 = root.left; // 2
        TreeNode q2 = root.left.right; // 4
        System.out.println("LCA of 2 and 4: " + lowestCommonAncestor(root, p2, q2).val); // Output: 2
    }
}
