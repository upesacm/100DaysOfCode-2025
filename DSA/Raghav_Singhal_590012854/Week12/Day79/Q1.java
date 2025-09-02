class Node {
    int data;
    Node left, right;
    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class Q1 {
    Node root;

    void inorder(Node node) {
        if (node == null) return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    public static void main(String[] args) {
        Q1 tree = new Q1();
        tree.root = new Node(5);
        tree.root.left = new Node(3);
        tree.root.right = new Node(7);
        tree.root.left.left = new Node(2);
        tree.root.left.right = new Node(4);
        tree.inorder(tree.root);
        System.out.println();
        Q1 tree2 = new Q1();
        tree2.root = new Node(10);
        tree2.root.left = new Node(8);
        tree2.root.right = new Node(12);
        tree2.inorder(tree2.root);
    }
}
