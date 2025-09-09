// Filename: Question1.java

import java.util.*;

// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

// Helper class to store node with its row and column
class Tuple {
    TreeNode node;
    int row;
    int col;

    Tuple(TreeNode _node, int _row, int _col) {
        node = _node;
        row = _row;
        col = _col;
    }
}

public class Question1 {

    // Vertical Order Traversal
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        Queue<Tuple> q = new LinkedList<>();
        q.offer(new Tuple(root, 0, 0));

        while (!q.isEmpty()) {
            Tuple tuple = q.poll();
            TreeNode node = tuple.node;
            int row = tuple.row;
            int col = tuple.col;

            map.putIfAbsent(col, new TreeMap<>());
            map.get(col).putIfAbsent(row, new PriorityQueue<>());
            map.get(col).get(row).offer(node.val);

            if (node.left != null) q.offer(new Tuple(node.left, row + 1, col - 1));
            if (node.right != null) q.offer(new Tuple(node.right, row + 1, col + 1));
        }

        List<List<Integer>> result = new ArrayList<>();
        for (TreeMap<Integer, PriorityQueue<Integer>> ys : map.values()) {
            List<Integer> colList = new ArrayList<>();
            for (PriorityQueue<Integer> nodes : ys.values()) {
                while (!nodes.isEmpty()) {
                    colList.add(nodes.poll());
                }
            }
            result.add(colList);
        }
        return result;
    }

    // Function to build tree from level-order input
    public static TreeNode buildTree(Scanner sc) {
        System.out.print("Enter root value (-1 for null): ");
        int rootVal = sc.nextInt();
        if (rootVal == -1) return null;

        TreeNode root = new TreeNode(rootVal);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            System.out.print("Enter left child of " + current.val + " (-1 for null): ");
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                current.left = new TreeNode(leftVal);
                queue.offer(current.left);
            }

            System.out.print("Enter right child of " + current.val + " (-1 for null): ");
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                current.right = new TreeNode(rightVal);
                queue.offer(current.right);
            }
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree from user input
        TreeNode root = buildTree(sc);

        Question1 solution = new Question1();
        List<List<Integer>> ans = solution.verticalTraversal(root);

        System.out.println("Vertical Order Traversal:");
        for (List<Integer> col : ans) {
            System.out.println(col);
        }

        sc.close();
    }
}
