import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left == null) return right;
        else if (right == null) return left;
        else return root;
    }
}

public class Question1 {
    static Scanner sc = new Scanner(System.in);

    public static TreeNode buildTree() {
        System.out.println("Enter root value (-1 for null): ");
        int val = sc.nextInt();
        if (val == -1) return null;

        TreeNode root = new TreeNode(val);
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode curr = q.poll();

            System.out.println("Enter left child of " + curr.val + " (-1 for null): ");
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                curr.left = new TreeNode(leftVal);
                q.add(curr.left);
            }

            System.out.println("Enter right child of " + curr.val + " (-1 for null): ");
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                curr.right = new TreeNode(rightVal);
                q.add(curr.right);
            }
        }

        return root;
    }

    public static TreeNode findNode(TreeNode root, int val) {
        if (root == null) return null;
        if (root.val == val) return root;
        TreeNode left = findNode(root.left, val);
        if (left != null) return left;
        return findNode(root.right, val);
    }

    public static void main(String[] args) {
        TreeNode root = buildTree();

        System.out.println("Enter first node value (p): ");
        int pVal = sc.nextInt();
        System.out.println("Enter second node value (q): ");
        int qVal = sc.nextInt();

        TreeNode p = findNode(root, pVal);
        TreeNode q = findNode(root, qVal);

        if (p == null || q == null) {
            System.out.println("One or both nodes not found in the tree.");
            return;
        }

        Solution sol = new Solution();
        TreeNode lca = sol.lowestCommonAncestor(root, p, q);

        System.out.println(lca.val);
    }
}
