public class Day_81_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    // Helper to flatten BST to sorted linked list
    private static ListNode prev = null, head = null;

    public static ListNode bstToSortedList(TreeNode root) {
        prev = null;
        head = null;
        inorder(root);
        return head;
    }

    private static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        ListNode node = new ListNode(root.val);
        if (prev == null) head = node;
        else prev.next = node;
        prev = node;
        inorder(root.right);
    }

    // Print linked list
    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val);
            if (node.next != null) System.out.print(" → ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Example 1: Tree 4 / \ 2 6 / \ / \ 1 3 5 7
        TreeNode root1 = new TreeNode(4);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(6);
        root1.left.left = new TreeNode(1);
        root1.left.right = new TreeNode(3);
        root1.right.left = new TreeNode(5);
        root1.right.right = new TreeNode(7);

        ListNode list1 = bstToSortedList(root1);
        printList(list1); // Output: 1 → 2 → 3 → 4 → 5 → 6 → 7

        // Example 2: Tree 2 / \ 1 3
        TreeNode root2 = new TreeNode(2);
        root2.left = new TreeNode(1);
        root2.right = new TreeNode(3);

        ListNode list2 = bstToSortedList(root2);
        printList(list2); // Output: 1 → 2 → 3
    }
}
