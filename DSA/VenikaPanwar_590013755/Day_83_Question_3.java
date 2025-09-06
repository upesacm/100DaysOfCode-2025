import java.util.*;

public class Day_83_Question_3 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Checks if there exist two nodes whose sum equals target
    public static boolean findTarget(TreeNode root, int k) {
        List<Integer> nums = new ArrayList<>();
        inorder(root, nums);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums.get(left) + nums.get(right);
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }

    private static void inorder(TreeNode root, List<Integer> nums) {
        if (root == null) return;
        inorder(root.left, nums);
        nums.add(root.val);
        inorder(root.right, nums);
    }

    public static void main(String[] args) {
        // Example 1: Tree 5 / \ 3 6 / \ \ 2 4 7, Target = 9
        TreeNode root1 = new TreeNode(5);
        root1.left = new TreeNode(3);
        root1.right = new TreeNode(6);
        root1.left.left = new TreeNode(2);
        root1.left.right = new TreeNode(4);
        root1.right.right = new TreeNode(7);
        System.out.println("Two Sum 9: " + (findTarget(root1, 9) ? "Yes" : "No")); // Output: Yes

        // Example 2: Target = 28
        System.out.println("Two Sum 28: " + (findTarget(root1, 28) ? "Yes" : "No")); // Output: No
    }
}
