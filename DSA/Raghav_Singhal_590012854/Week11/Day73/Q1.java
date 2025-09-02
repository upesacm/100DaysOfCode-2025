class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q1 {
    public static int sumOfNodes(Node root) {
        if (root == null) return 0;
        return root.data + sumOfNodes(root.left) + sumOfNodes(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);

        System.out.println(sumOfNodes(root));

        Node root2 = new Node(5);
        root2.left = new Node(7);
        root2.right = new Node(6);

        System.out.println(sumOfNodes(root2));
    }
}
