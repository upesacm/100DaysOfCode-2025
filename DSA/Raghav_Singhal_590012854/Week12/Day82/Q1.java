class Node {
    int data;
    Node left, right;
    Node(int val) { data = val; left = right = null; }
}

public class Q1 {
    public static Node sortedArrayToBST(int[] nums, int start, int end) {
        if (start > end) return null;
        int mid = start + (end - start) / 2;
        Node root = new Node(nums[mid]);
        root.left = sortedArrayToBST(nums, start, mid - 1);
        root.right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }

    public static void preorder(Node root) {
        if (root == null) return;
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7};
        Node root = sortedArrayToBST(nums, 0, nums.length - 1);
        preorder(root);
    }
}
