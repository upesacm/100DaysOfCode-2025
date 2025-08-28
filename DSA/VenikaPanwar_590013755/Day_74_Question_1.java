public class Day_74_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Prints all nodes at distance k from root
    public static void printKDistance(TreeNode root, int k) {
        if (root == null) return;
        if (k == 0) {
            System.out.print(root.val + " ");
            return;
        }
        printKDistance(root.left, k - 1);
        printKDistance(root.right, k - 1);
    }

    public static void main(String[] args) {
        // Example: Tree 1 / \ 2 3 / \ 4 5, K=2
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("Nodes at distance 2: ");
        printKDistance(root, 2); // Output: 4 5
        System.out.println();
    }
}