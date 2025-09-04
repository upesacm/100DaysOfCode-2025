class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class Q3 {
    public static void printRange(Node root, int L, int R) {
        if (root == null) return;
        if (root.data > L) printRange(root.left, L, R);
        if (root.data >= L && root.data <= R) System.out.print(root.data + " ");
        if (root.data < R) printRange(root.right, L, R);
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(15);
        root.left.left = new Node(3);
        root.left.right = new Node(7);
        root.right.right = new Node(18);

        int L = 7, R = 15;
        printRange(root, L, R);
    }
}
