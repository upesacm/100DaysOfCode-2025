import java.util.*;

// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class Question3 {

    // Function to count nodes in a complete binary tree
    public int countNodes(TreeNode root) {
        if (root == null) return 0;

        int left = getHeightLeft(root);
        int right = getHeightRight(root);

        // If left and right heights are equal, it's a perfect binary tree
        if (left == right) {
            return (1 << left) - 1; // 2^height - 1
        }

        // Otherwise, count recursively
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    // Get height following the left children
    public int getHeightLeft(TreeNode root) {
        int count = 0;
        while (root != null) {
            count++;
            root = root.left;
        }
        return count;
    }

    // Get height following the right children
    public int getHeightRight(TreeNode root) {
        int count = 0;
        while (root != null) {
            count++;
            root = root.right;
        }
        return count;
    }

    // Build tree from level order input
    public static TreeNode buildTree(List<Integer> values) {
        if (values.isEmpty() || values.get(0) == -1) return null;

        TreeNode root = new TreeNode(values.get(0));
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        int i = 1;
        while (i < values.size()) {
            TreeNode current = queue.poll();
            if (current != null) {
                // Left child
                if (values.get(i) != -1) {
                    current.left = new TreeNode(values.get(i));
                    queue.add(current.left);
                }
                i++;
                if (i >= values.size()) break;

                // Right child
                if (values.get(i) != -1) {
                    current.right = new TreeNode(values.get(i));
                    queue.add(current.right);
                }
                i++;
            }
        }
        return root;
    }

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question3 solution = new Question3();

        System.out.println("Enter the number of nodes:");
        int n = sc.nextInt();

        System.out.println("Enter tree nodes in level-order (-1 for null):");
        List<Integer> values = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            values.add(sc.nextInt());
        }

        TreeNode root = buildTree(values);
        int result = solution.countNodes(root);

        System.out.println(result);

        sc.close();
    }
}
