import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) {
        val = x;
    }
}

public class Question3 {

    // Function to construct Maximum Binary Tree
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return build(nums, 0, nums.length - 1);
    }

    // Helper recursive build method
    private TreeNode build(int[] nums, int start, int end) {
        if (start > end) return null;

        // Find index of maximum value in nums[start..end]
        int idxMax = start;
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] > nums[idxMax]) {
                idxMax = i;
            }
        }

        // Create root with max element
        TreeNode root = new TreeNode(nums[idxMax]);

        // Recursively build left and right subtrees
        root.left = build(nums, start, idxMax - 1);
        root.right = build(nums, idxMax + 1, end);

        return root;
    }

    // Recursive function to find maximum value in the tree
    public int findMax(TreeNode root) {
        if (root == null) {
            return Integer.MIN_VALUE; // base case
        }

        // Recursively check left and right subtrees
        int leftMax = findMax(root.left);
        int rightMax = findMax(root.right);

        // Return the maximum among root, leftMax, and rightMax
        return Math.max(root.val, Math.max(leftMax, rightMax));
    }

    // Print tree in Level Order for visualization
    public void printLevelOrder(TreeNode root) {
        if (root == null) return;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                System.out.print(node.val + " ");
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            System.out.println();
        }
    }

    // Main method - take input from user
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        Question3 solution = new Question3();
        TreeNode root = solution.constructMaximumBinaryTree(nums);

       // System.out.println("\nLevel Order Traversal of Maximum Binary Tree:");
        //solution.printLevelOrder(root);

        // Find max value recursively
        int maxValue = solution.findMax(root);
        System.out.println(maxValue);
    }
}
