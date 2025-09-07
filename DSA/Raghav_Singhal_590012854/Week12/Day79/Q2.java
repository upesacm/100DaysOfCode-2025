class Node {
    int data;
    Node left, right;
    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class Q2 {
    Node root;

    int countNodes(Node node) {
        if (node == null) return 0;
        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    public static void main(String[] args) {
        Q2 tree = new Q2();
        tree.root = new Node(5);
        tree.root.left = new Node(3);
        tree.root.right = new Node(7);
        System.out.println(tree.countNodes(tree.root));
        Q2 tree2 = new Q2();
        tree2.root = new Node(8);
        tree2.root.left = new Node(6);
        tree2.root.right = new Node(10);
        tree2.root.left.left = new Node(4);
        System.out.println(tree2.countNodes(tree2.root));
    }
}
