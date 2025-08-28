class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q2 {
    public static int checkHeight(Node root) {
        if (root == null) return 0;
        int leftHeight = checkHeight(root.left);
        if (leftHeight == -1) return -1;
        int rightHeight = checkHeight(root.right);
        if (rightHeight == -1) return -1;
        if (Math.abs(leftHeight - rightHeight) > 1) return -1;
        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static boolean isBalanced(Node root) {
        return checkHeight(root) != -1;
    }

    public static void main(String[] args) {
        Node root1 = new Node(1);
        root1.left = new Node(2);
        root1.right = new Node(3);
        root1.left.left = new Node(4);
        root1.left.right = new Node(5);
        root1.right.left = new Node(6);
        root1.right.right = new Node(7);
        System.out.println(isBalanced(root1));

        Node root2 = new Node(1);
        root2.left = new Node(2);
        root2.left.left = new Node(3);
        root2.left.left.left = new Node(4);
        System.out.println(isBalanced(root2));

        Node root3 = new Node(10);
        root3.right = new Node(20);
        root3.right.right = new Node(30);
        root3.left = new Node(15);
        System.out.println(isBalanced(root3));
    }
}
