import java.util.List;
import java.util.ArrayList;

public class Day_74_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Helper to print all root-to-leaf paths
    public static void printPaths(TreeNode root) {
        List<Integer> path = new ArrayList<>();
        printPathsHelper(root, path);
    }

    private static void printPathsHelper(TreeNode node, List<Integer> path) {
        if (node == null) return;
        path.add(node.val);
        if (node.left == null && node.right == null) {
            // Leaf node, print path
            for (int i = 0; i < path.size(); i++) {
                System.out.print(path.get(i));
                if (i < path.size() - 1) System.out.print("->");
            }
            System.out.println();
        } else {
            printPathsHelper(node.left, path);
            printPathsHelper(node.right, path);
        }
        path.remove(path.size() - 1); // Backtrack
    }

    public static void main(String[] args) {
        // Example: Tree 1 / \ 2 3 \ 5
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(5);

        System.out.println("Root to leaf paths:");
        printPaths(root); // Output: 1->2->5 and 1->3
    }
}