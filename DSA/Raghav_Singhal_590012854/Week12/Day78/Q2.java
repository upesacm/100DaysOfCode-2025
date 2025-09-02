class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q2 {
    public static Node insertBst(Node root, int e) {
        if (root == null) return new Node(e);

        if (e < root.data) {
            root.left = insertBst(root.left, e);
        } else if (e > root.data) {
            root.right = insertBst(root.right, e);
        }
        return root;
    }

    public static void inorderTraversal(Node root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(5);
        root.left = new Node(3);
        root.right = new Node(7);

        insertBst(root, 4);

        System.out.print("Inorder Traversal of BST: ");
        inorderTraversal(root);
    }
}
