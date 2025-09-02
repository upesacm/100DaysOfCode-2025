class Node {
    int data;
    Node left, right;
    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class Q3 {
    Node root;

    boolean isValidBST(Node node, long min, long max) {
        if (node == null) return true;
        if (node.data <= min || node.data >= max) return false;
        return isValidBST(node.left, min, node.data) && isValidBST(node.right, node.data, max);
    }

    public static void main(String[] args) {
        Q3 tree = new Q3();
        tree.root = new Node(2);
        tree.root.left = new Node(1);
        tree.root.right = new Node(3);
        System.out.println(tree.isValidBST(tree.root, Long.MIN_VALUE, Long.MAX_VALUE) ? "Yes" : "No");
        Q3 tree2 = new Q3();
        tree2.root = new Node(5);
        tree2.root.left = new Node(1);
        tree2.root.right = new Node(4);
        tree2.root.right.left = new Node(3);
        tree2.root.right.right = new Node(6);
        System.out.println(tree2.isValidBST(tree2.root, Long.MIN_VALUE, Long.MAX_VALUE) ? "Yes" : "No");
    }
}
