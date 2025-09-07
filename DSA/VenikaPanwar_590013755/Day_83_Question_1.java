import java.util.*;

public class Day_83_Question_1 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Returns vertical order traversal as list of lists
    public static List<List<Integer>> verticalOrder(TreeNode root) {
        Map<Integer, List<Integer>> columnMap = new TreeMap<>();
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        Queue<Integer> colQueue = new LinkedList<>();
        if (root == null) return new ArrayList<>();
        nodeQueue.offer(root);
        colQueue.offer(0);
        while (!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.poll();
            int col = colQueue.poll();
            columnMap.computeIfAbsent(col, k -> new ArrayList<>()).add(node.val);
            if (node.left != null) {
                nodeQueue.offer(node.left);
                colQueue.offer(col - 1);
            }
            if (node.right != null) {
                nodeQueue.offer(node.right);
                colQueue.offer(col + 1);
            }
        }
        return new ArrayList<>(columnMap.values());
    }

    public static void main(String[] args) {
        // Example 1: Tree 3 / \ 9 20 / \ 15 7
        TreeNode root1 = new TreeNode(3);
        root1.left = new TreeNode(9);
        root1.right = new TreeNode(20);
        root1.right.left = new TreeNode(15);
        root1.right.right = new TreeNode(7);
        System.out.println(verticalOrder(root1)); // Output: [[9], [3, 15], [20], [7]]

        // Example 2: Tree 4 / \ 2 6 / \ / \ 1 3 5 7
        TreeNode root2 = new TreeNode(4);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(6);
        root2.left.left = new TreeNode(1);
        root2.left.right = new TreeNode(3);
        root2.right.left = new TreeNode(5);
        root2.right.right = new TreeNode(7);
        System.out.println(verticalOrder(root2)); // Output: [[1], [2], [4, 3, 5, 6], [7]]
    }
}
