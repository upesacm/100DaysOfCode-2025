class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q1 {
    public static void printNodesAtK(Node root, int k) {
        if (root == null) return;
        if (k == 0) {
            System.out.print(root.data + " ");
            return;
        }
        printNodesAtK(root.left, k - 1);
        printNodesAtK(root.right, k - 1);
    }

    public static void main(String[] args) {
        Node root1 = new Node(1);
        root1.left = new Node(2);
        root1.right = new Node(3);
        root1.left.left = new Node(4);
        root1.left.right = new Node(5);
        root1.right.left = new Node(6);
        root1.right.right = new Node(7);
        printNodesAtK(root1, 2);
        System.out.println();

        Node root2 = new Node(10);
        root2.right = new Node(20);
        root2.right.right = new Node(30);
        printNodesAtK(root2, 1);
        System.out.println();

        Node root3 = new Node(5);
        root3.left = new Node(8);
        root3.left.right = new Node(12);
        root3.right = new Node(9);
        printNodesAtK(root3, 2);
    }
}
