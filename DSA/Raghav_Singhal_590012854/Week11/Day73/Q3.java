class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q3 {
    public static int findMax(Node root) {
        if (root == null) return Integer.MIN_VALUE;
        int leftMax = findMax(root.left);
        int rightMax = findMax(root.right);
        return Math.max(root.data, Math.max(leftMax, rightMax));
    }

    public static void main(String[] args) {
        Node root1 = new Node(1);
        root1.left = new Node(2);
        root1.right = new Node(3);
        System.out.println(findMax(root1));

        Node root2 = new Node(10);
        root2.right = new Node(20);
        System.out.println(findMax(root2));

        Node root3 = new Node(7);
        root3.left = new Node(9);
        root3.right = new Node(5);
        root3.left.left = new Node(15);
        root3.left.right = new Node(6);
        System.out.println(findMax(root3));
    }
}
