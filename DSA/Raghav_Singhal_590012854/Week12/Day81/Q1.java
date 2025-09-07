class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class Q1 {
    public static int rangeSum(Node root, int L, int R) {
        if (root == null) return 0;
        if (root.data < L) return rangeSum(root.right, L, R);
        if (root.data > R) return rangeSum(root.left, L, R);
        return root.data + rangeSum(root.left, L, R) + rangeSum(root.right, L, R);
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(15);
        root.left.left = new Node(3);
        root.left.right = new Node(7);
        root.right.right = new Node(18);

        int L = 7, R = 15;
        System.out.println(rangeSum(root, L, R));
    }
}
