class Node {
    int data;
    Node left, right;
    Node(int val) { data = val; left = right = null; }
}

public class Q2 {
    public static int checkHeight(Node root) {
        if (root == null) return 0;
        int left = checkHeight(root.left);
        if (left == -1) return -1;
        int right = checkHeight(root.right);
        if (right == -1) return -1;
        if (Math.abs(left - right) > 1) return -1;
        return Math.max(left, right) + 1;
    }

    public static boolean isBalanced(Node root) {
        return checkHeight(root) != -1;
    }

    public static void main(String[] args) {
        Node root1 = new Node(4);
        root1.left = new Node(2);
        root1.right = new Node(6);
        root1.left.left = new Node(1);
        root1.left.right = new Node(3);
        root1.right.left = new Node(5);
        root1.right.right = new Node(7);
        System.out.println(isBalanced(root1) ? "Yes" : "No");

        Node root2 = new Node(1);
        root2.right = new Node(2);
        root2.right.right = new Node(3);
        System.out.println(isBalanced(root2) ? "Yes" : "No");
    }
}
