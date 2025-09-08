// Filename: Question3.java

import java.util.*;

// Definition of a binary tree node
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

// Iterator class for BST (inorder and reverse inorder)
class BSTIterator {
    private Stack<TreeNode> stack = new Stack<>();
    private boolean reverse;

    public BSTIterator(TreeNode root, boolean isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }

    public int next() {
        TreeNode node = stack.pop();
        if (!reverse) pushAll(node.right);
        else pushAll(node.left);
        return node.val;
    }

    private void pushAll(TreeNode node) {
        while (node != null) {
            stack.push(node);
            if (reverse) node = node.right;
            else node = node.left;
        }
    }
}

public class Question3 {

    // Function to check if there exists a pair with sum k
    public boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;

        BSTIterator l = new BSTIterator(root, false); // inorder
        BSTIterator r = new BSTIterator(root, true);  // reverse inorder

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) {
                if (l.hasNext()) i = l.next();
                else return false;
            } else {
                if (r.hasNext()) j = r.next();
                else return false;
            }
        }
        return false;
    }

    // Build BST from user input (level order)
    public static TreeNode buildTree(Scanner sc) {
        int rootVal = sc.nextInt();
        if (rootVal == -1) return null;

        TreeNode root = new TreeNode(rootVal);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                current.left = new TreeNode(leftVal);
                queue.add(current.left);
            }

            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                current.right = new TreeNode(rightVal);
                queue.add(current.right);
            }
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input format: level-order with -1 for nulls
        // Example for tree in problem:
        // 5 3 6 2 4 -1 7 -1 -1 -1 -1 -1 -1
        TreeNode root = buildTree(sc);

        int k = sc.nextInt();

        Question3 solution = new Question3();
        boolean exists = solution.findTarget(root, k);

        if (exists) System.out.println("Yes");
        else System.out.println("No");

        sc.close();
    }
}
