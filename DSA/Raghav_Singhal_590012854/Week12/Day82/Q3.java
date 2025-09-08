class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class Q3 {
    static int sum = 0;

    public static void convertToGreaterTree(Node root) {
        if (root == null) return;
        convertToGreaterTree(root.right);
        sum += root.data;
        root.data = sum;
        convertToGreaterTree(root.left);
    }

    public static void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(5);
        root.left = new Node(2);
        root.right = new Node(13);

        convertToGreaterTree(root);

        inorder(root);
    }
}
